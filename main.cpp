#include <cstdio>
#include <cmath>
#include <vector>
double sqr(double x)
{
    return x*x;
}

double curvature(const std::vector<double>& p1,const std::vector<double>& p2,const std::vector<double>& p3)
{ 
    //for curvature=1.0/radius
    return 1.0/(sqrt(((p1[0]*p1[0]-2.0*p1[0]*p2[0]+p2[0]*p2[0]+(p1[1]-p2[1])*(p1[1]-p2[1]))
                *(p1[0]*p1[0]-2.0*p1[0]*p3[0]+p3[0]*p3[0]+(p1[1]-p3[1])*(p1[1]-p3[1]))
                *(p2[0]*p2[0]-2.0*p2[0]*p3[0]+ p3[0]*p3[0] + (p2[1]-p3[1])*(p2[1]-p3[1])))
                /(4.0*(p3[0]*(-p1[1]+p2[1])+p2[0]*(p1[1]-p3[1])+p1[0]*(-p2[1]+p3[1]))
                *(p3[0]*(-p1[1]+p2[1])+p2[0]*(p1[1]-p3[1])+p1[0]*(-p2[1]+p3[1])))));
}

int main(int argc, char **argv) {
    std::vector<double> p1(2),p2(2),p3(2);
    p1.at(0)=0.0;
    p1.at(1)=1.0;
    p2.at(0)=1.0;
    p2.at(1)=0.0;
    p3.at(0)=1.0-sqrt(2.0)/2.0;
    p3.at(1)=1.0-sqrt(2.0)/2.0;
    
    double r=curvature(p1,p2,p3);
    printf("r: %f\n",r);
    
    return 0;
}
