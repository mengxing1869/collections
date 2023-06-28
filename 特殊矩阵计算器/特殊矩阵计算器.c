#include<stdio.h>
#include<stdlib.h>

typedef struct{
    float *sa;  //�����õ�һά����ָ��
    int n;    //�����������
    int kind; //������������
    int x;    //����Ϊ�ԽǾ���ʱ�ĶԽ���
	int num;  //һά��������ݸ���
}Matrix;

void Print_Mat(float **matrix,int a)
{
    int i,j;
	for(i=0;i<a;i++)
	{
		for(j=0;j<a;j++)
			printf("%.2f\t",matrix[i][j]);
		printf("\n\n");
	}
}

void Upper_Triangular(Matrix *mat)  //�������Ǿ�������
{
    int i;
    printf("������þ������������");
    scanf("%d",&mat->n);
    mat->num=(mat->n+1)*mat->n/2+1;
    mat->sa=(float*)malloc(mat->num*sizeof(float));
    printf("������Ϊ������������%d������(���һ�������������еĳ���):\n",mat->num);
    for(i=0;i<mat->num;i++)
    {
        scanf("%f",&mat->sa[i]);
    }
}

void Lower_Triangular(Matrix *mat)  //�����Ǿ�������
{   
    int i;
    printf("������þ������������");
    scanf("%d",&mat->n);
    mat->num=(mat->n+1)*mat->n/2+1;
    mat->sa=(float*)malloc(mat->num*sizeof(float));
    printf("������Ϊ������������%d������(���һ�������������еĳ���):\n",mat->num);
    for(i=0;i<mat->num;i++)
    {
        scanf("%f",&mat->sa[i]);
    }
}

void Symmetric(Matrix *mat)  //�Գƾ�������
{
    int i;
    printf("������þ������������");
    scanf("%d",&mat->n);
    mat->num=(mat->n+1)*mat->n/2;
    mat->sa=(float*)malloc(mat->num*sizeof(float));
    printf("������Ϊ������������þ�����������%d������:\n",mat->num);
    for(i=0;i<mat->num;i++)
    {
        scanf("%f",&mat->sa[i]);
    }
}

void Diagonal(Matrix *mat)  //�ԽǾ�������
{
    int i;
    printf("������þ������������");
    scanf("%d",&mat->n);
    printf("������þ���ĶԽ�����(������С��������)");
    scanf("%d",&mat->x);
	mat->num=mat->n*mat->x-(1+mat->x/2)*(mat->x/2);
	printf("������Ϊ������������%d������:\n",mat->num);
	mat->sa=(float*)malloc(mat->num*sizeof(float));
	for(i=0;i<mat->num;i++)
    {
        scanf("%f",&mat->sa[i]);
    }
}

void Unit(Matrix *mat)
{
    printf("������������������");
    scanf("%d",&mat->n);
}

void Import_Mat(Matrix *mat,int i)  //��������
{
    printf("��ѡ�����%d������\n",i);
    printf("1�������Ǿ���\n");
    printf("2�������Ǿ���\n");
    printf("3���Գƾ���\n");
    printf("4���ԽǾ���\n");
    printf("5����λ����\n\n");
    scanf("%d",&mat->kind);
    switch(mat->kind){
    case 1:Upper_Triangular(mat);break;
    case 2:Lower_Triangular(mat);break;
    case 3:Symmetric(mat);break;
    case 4:Diagonal(mat);break;
    case 5:Unit(mat);break;
    default:printf("������������������\n");Import_Mat(mat,i);return;
    }
	printf("����%d¼�����!\n",i);
}

float** Uncompress(Matrix mat)   //ѹ�������ѹ
{
	int a,i,j;
    float **matrix;
	matrix=(float**)malloc(mat.n*sizeof(float*));
	for(i=0;i<mat.n;i++)
		matrix[i]=(float*)malloc(mat.n*sizeof(float));
	a=0;
	switch(mat.kind){
	case 1:
		{
			for(i=0;i<mat.n;i++)
				for(j=0;j<mat.n;j++)
				{
					if(i<=j)
						matrix[i][j]=mat.sa[a++];
					else
						matrix[i][j]=mat.sa[mat.num-1];
				}
		}
		break;
	case 2:
		{
			for(i=0;i<mat.n;i++)
				for(j=0;j<mat.n;j++)
				{
					if(i>=j)
						matrix[i][j]=mat.sa[a++];
					else
						matrix[i][j]=mat.sa[mat.num-1];
				}
		}
		break;
	case 3:
		{
			for(i=0;i<mat.n;i++)
				for(j=i;j<mat.n;j++)
				{
					if(i==j)
					{
						matrix[i][j]=mat.sa[a++];
					}
					else
					{
						matrix[i][j]=matrix[j][i]=mat.sa[a++];
					}
				}
		}
		break;
	case 4:
		{
			for(i=0;i<mat.n;i++)
				for(j=0;j<mat.n;j++)
				{
					if(j<=(i+mat.x/2)&&j>=(i-mat.x/2))
					{
						matrix[i][j]=mat.sa[a++];
					}
					else
					{
						matrix[i][j]=0;
					}
				}
		}
		break;
	case 5:
		{
			for(i=0;i<mat.n;i++)
				for(j=0;j<mat.n;j++)
				{
					if(i==j)
						matrix[i][j]=1;
					else
						matrix[i][j]=0;
				}
		}
		break;
	}
	return matrix;
}



float Mat(Matrix mat,int a,int b)   //����ѹ������mat��a��b�е����ݣ�û�з���0
{
	int x=0;     //xΪѹ������洢��a��֮ǰ�����ݸ���
	switch(mat.kind){
	case 1:
		{
			if(a<=b)
			{
				x=(2*mat.n-a+1)*a/2;
				return mat.sa[x+b-a];
			}
            else
			    return mat.sa[mat.num-1];
		}
		break;
	case 2:
		{
			if(a>=b)
			{
				x=(a+1)*a/2;
				return mat.sa[x+b];
			}
            else
			    return mat.sa[mat.num-1];
		}
		break;
	case 3:
		{
			if(a<=b)
			{
				x=(2*mat.n-a+1)*a/2;
				return mat.sa[x+b-a];
			}
			else
			{
				x=(2*mat.n-b+1)*b/2;
				return mat.sa[x+a-b];
			}
		}
		break;
	case 4:
		{
			if(b<=a+mat.x/2&&b>=a-mat.x/2)
			{
			    if(a<mat.x/2)
				{
			        x=(a-1+2*(mat.x/2+1))*a/2;
					return mat.sa[x+b];
				}
			    else if(a<(mat.n-mat.x/2))
				{
				    x=a*mat.x-(mat.x/2+1)*(mat.x/2)/2;
					return mat.sa[x+b-a+mat.x/2];
				}
				else 
				{
					x=a*mat.x-(mat.x/2+1)*(mat.x/2)/2-(a+mat.x/2-mat.n+1)*(a+mat.x/2-mat.n)/2;
				    return mat.sa[x+b-a+mat.x/2];
				}
			}
			else
			    return 0;
		}
		break;
	case 5:
		{
			if(a==b)
				return 1;
			else return 0;
		}
		break;
	}
	return 0;
}

void Matrix_Add(Matrix mat1,Matrix mat2)   //����ӷ�
{
	int i,j;
	if(mat1.n!=mat2.n)
		printf("���㲻���У�\n\n");
	else
	{
        printf("��Ӻ�Ϊ:\n\n");
		for(i=0;i<mat1.n;i++)
		{
			for(j=0;j<mat1.n;j++)
			{
				printf("%.2f\t",Mat(mat1,i,j)+Mat(mat2,i,j));
			}
			printf("\n\n");
		}
	}

}

void Matrix_Minus(Matrix mat1,Matrix mat2)  //�������
{
	int i,j;
	if(mat1.n!=mat2.n)
		printf("���㲻���У�\n\n");
	else
	{
		printf("�����Ϊ:\n\n");
		for(i=0;i<mat1.n;i++)
		{
			for(j=0;j<mat1.n;j++)
			{
				printf("%.2f\t",Mat(mat1,i,j)-Mat(mat2,i,j));
			}
			printf("\n\n");
		}
	}
}

void Matrix_Ride(Matrix mat1,Matrix mat2)  //����˷�
{
	int i,j,k;
	float a;
	if(mat1.n!=mat2.n)
		printf("���㲻���У�\n\n");
	else
	{
		printf("��˺�Ϊ:\n\n");
		for(i=0;i<mat1.n;i++)
		{
			for(j=0;j<mat1.n;j++)
			{
				a=0;
				for(k=0;k<mat1.n;k++)
				{
					a=a+Mat(mat1,i,k)*Mat(mat2,k,j);
				}
				printf("%.2f\t",a);
			}
			printf("\n\n");
		}
	}
}

void Matrix_Transpose(Matrix mat)   //����ת��
{
	int i,j;
	printf("ת�ú�Ϊ:\n\n");
	for(i=0;i<mat.n;i++)
	{
		for(j=0;j<mat.n;j++)
			printf("%.2f\t",Mat(mat,j,i));
		printf("\n\n");
	}

}

float** Algebraic_Complement(float **matrix,int x,int y,int n)  //�����matrix��x��y�еĴ���������
{
    float **mat;
	int a,b,i,j;
	mat=(float**)malloc((n-1)*sizeof(float*));
	for(i=0;i<n-1;i++)
		mat[i]=(float*)malloc((n-1)*sizeof(float));   //�����¾���mat��ʹ��������Ϊn-1
	a=0;
	for(i=0;i<n;i++)   //ʹ����mat���ھ���Ԫ��matirx[x][y]��������
	{
		if(i!=x)
		{
		    b=0;
		    for(j=0;j<n;j++)
			{
			    if(j!=y)
				{
		           mat[a][b++]=matrix[i][j];
				}
			}
			a++;
		}
	}
	return mat;
}

float Matrix_Det(float **matrix,int n)   //��������ʽ
{ 
	float **mat;
	int k;
	float x;       //���������ʽֵ
	if(n==2)                                                           
		return matrix[0][0]*matrix[1][1]-matrix[0][1]*matrix[1][0];  //����������Ϊ2ʱֱ�ӷ�������ʽֵ
	if(n==1)
		return matrix[0][0];
	x=0;
	for(k=0;k<n;k++)
	{
		mat=Algebraic_Complement(matrix,0,k,n);      //ʹmatΪ������0��k�еĴ���������
		if(k%2==0)                                   //ÿ��ѭ��ʹx���ϻ��ȥ��ǰ����Ԫ�������������ʽ�Ļ�
		    x=x+matrix[0][k]*Matrix_Det(mat,n-1);    //ѭ������x��Ϊ��ǰ���������ʽֵ
		else
			x=x-matrix[0][k]*Matrix_Det(mat,n-1);
	}
	for(k=0;k<n-1;k++)
	    free(mat[k]);
	free(mat);
	return x;   //���ص���ִ�г������õ�����ʽֵ
}

void Matrix_Inverse(float **matrix,int n)   //�������
{
	float **mat;
	int i,j,k;
	float a,b;
	a=Matrix_Det(matrix,n);            //�����matrix������ʽ
	if(a==0)
	{
		printf("�þ���û����!\n\n");
		return;
	}
	printf("�����Ϊ��\n");
    for(i=0;i<n;i++)
	{
		for(j=0;j<n;j++)
		{
			mat=Algebraic_Complement(matrix,j,i,n);   //�������j��i�е�����ʽ
			b=Matrix_Det(mat,n-1);                    //
			if((i+j)%2==1)
				b=0-b;
			printf("%f\t",b/a);  //�������matrix�������mat
			for(k=0;k<n-1;k++)
	            free(mat[k]);
	        free(mat);
		}
		printf("\n\n");
	}
}

void Matrix_Calculation(float **matrix1,float **matrix2,Matrix mat1,Matrix mat2)
{
	int a;
	while(1)
	{
        printf("��ѡ����Ҫִ�еĲ���\n");
        printf("1���������\n");
        printf("2���������\n");
        printf("3���������\n");
        printf("4������1����\n");
        printf("5������2����\n");
	    printf("6������1��ת��\n");
        printf("7������2��ת��\n");
        printf("8������1������ʽ\n");
        printf("9������2������ʽ\n");
	    printf("10���˳�����\n\n");
	    scanf("%d",&a);
		if(a==10) break;
	    switch(a){
	    case 1:Matrix_Add(mat1,mat2);break;
	    case 2:Matrix_Minus(mat1,mat2);break;
	    case 3:Matrix_Ride(mat1,mat2);break;
	    case 4:Matrix_Inverse(matrix1,mat1.n);break;
	    case 5:Matrix_Inverse(matrix2,mat2.n);break;
 	    case 6:Matrix_Transpose(mat1);break;
	    case 7:Matrix_Transpose(mat2);break;
	    case 8:printf("���Ϊ%.2f\n\n",Matrix_Det(matrix1,mat1.n));break;
	    case 9:printf("���Ϊ%.2f\n\n",Matrix_Det(matrix2,mat2.n));break;
	    default:printf("������������������\n");Matrix_Calculation(matrix1,matrix2,mat1,mat2);return;
		}
	}
}

int main()
{
	float **matrix1,**matrix2;   //�洢����Ķ�ά����ָ��
    Matrix mat1,mat2;          //ѹ������1��2
    Import_Mat(&mat1,1);
	printf("����1Ϊ:\n");
	matrix1=Uncompress(mat1);
	Print_Mat(matrix1,mat1.n);
    Import_Mat(&mat2,2);
	printf("����2Ϊ:\n");
	matrix2=Uncompress(mat2);
	Print_Mat(matrix2,mat2.n);
    Matrix_Calculation(matrix1,matrix2,mat1,mat2);
}
