#include<stdio.h>
#include<math.h>
int main(){
    double a,b,c,discriminant, root1, root2, realpart,imgpart;
    printf("The quefiients a, b, c are: ");
    scanf("%lf %lf %lf", &a, &b, &c);
    discriminant=b*b-4*a*c;
    if(discriminant>0){
        root1=(-b+sqrt(discriminant))/2*a;
        root2=(-b-sqrt(discriminant))/2*a;
        printf("Roots are real and distinct: %2lf %2lf\n",root1, root2);

    }
    else if(discriminant==0){
        root1=root2=-b/2*a;
        printf("roots are real and equal: %2lf and %2lf\n", root1,root2);
    }
    else{
        realpart=-b/2*a;
        imgpart=sqrt(discriminant);
        printf("rooths are imaginary and complex: %2lf+%2lf and %2lf-%2lf\n",realpart,imgpart,realpart,imgpart);
    }
    return 0;
}