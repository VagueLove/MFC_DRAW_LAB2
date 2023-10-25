#include"pch.h"
#include"CDrawVerLine.h"
CDrawVerLine::CDrawVerLine()
{
	pointset = false;
	lineset = false;
}
void CDrawVerLine::GetPoint(CPoint p)
{
	point = p;
	pointset = true;
}
void CDrawVerLine::GetLine(CLine* l)
{
	line = l;
	lineset = true;
}
void CDrawVerLine::GetVerFoot()
{
    double x1, y1, x2, y2, x3, y3;
    double foot_x, foot_y;
    x1 = (line->GetStart()).x;
    y1 = (line->GetStart()).y;
    x2 = (line->GetEnd()).x;
    y2 = (line->GetEnd()).y;
    x3 = point.x;
    y3 = point.y;
    calculate_foot(x1, y1, x2, y2, x3, y3, foot_x, foot_y);
    foot.x = foot_x;
    foot.y = foot_y;
}

double CDrawVerLine::dot_product(double x1, double y1, double x2, double y2) {
    return x1 * x2 + y1 * y2;
}

// �������������Ĳ�����
void CDrawVerLine::vector_difference(double x1, double y1, double x2, double y2, double& diff_x, double& diff_y) {
    diff_x = x2 - x1;
    diff_y = y2 - y1;
}

// �������������ĳ���
double CDrawVerLine::vector_length(double x, double y) {
    return sqrt(x * x + y * y);
}

// ���㴹�������
void CDrawVerLine::calculate_foot(double x1, double y1, double x2, double y2, double x3, double y3, double& foot_x, double& foot_y) {
    // �������������Ĳ�����
    double AB_x, AB_y;
    vector_difference(x1, y1, x2, y2, AB_x, AB_y);

    double AC_x, AC_y;
    vector_difference(x1, y1, x3, y3, AC_x, AC_y);

    // ���㴹�㵽A�������
    double proj = dot_product(AC_x, AC_y, AB_x, AB_y) / dot_product(AB_x, AB_y, AB_x, AB_y);
    double foot_vector_x = proj * AB_x;
    double foot_vector_y = proj * AB_y;

    // ���㴹�������
    foot_x = x1 + foot_vector_x;
    foot_y = y1 + foot_vector_y;
}

void CDrawVerLine::Draw(CDC* pDC,CSlist &list)
{
    Node* p = new Node;
    CLine* VerLine = new CLine;
    VerLine->Set_start_point(point);
    pDC->Ellipse(point.x - 2, point.y - 2, point.x + 2, point.y + 2);
    VerLine->Set_end_point(foot);
    p->now_type = 1;
    p->data = VerLine;
    list.InputFront(p);
    VerLine->Draw(pDC);
}