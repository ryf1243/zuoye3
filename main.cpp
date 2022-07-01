#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<time.h>
struct TransactionRecord
{
	char username[100];
	time_t timestamp;//ʱ���	
	int type;//�������� 0-ȡǮ��1-��Ǯ��2-ת����3-ת��
	int amount;//���� 
	
	struct TransactionRecord * next; 
}; 
typedef struct TransactionRecord TR;

TR * trHead=NULL;
TR * trTail=NULL; 

struct Account
{
	char username[100];
	char password[100];//����
	float money;
	float money1;
	int zh;//�˺�
	char flag[6];//����״̬
};


typedef struct Account Account;

Account user[1000];
int  userCount=0;
 
int curAccountIndex;
int otherAccountIndex;

void showMenu();//�˵�

void showChinese();//���Ĳ˵�


void Transfer();//ת��

void findOtherAccount();//����

int findAccount(Account a);//�����˻�

void saveTransactionRecord();//���潻�׼�¼

void Chinese();//��������


void closeaccount();//����


void searchAccoun();//���ݿ��Ų���ָ���˻������±�

void exit();//�˳�

int searchAccoun(int accNumber)
{
	int i,pos=-1;
	for(i=0;i<userCount;i++)
	{
		if(user[i].zh==accNumber&&strcmp(user[i].flag,"����")!=0)//�ҵ�����ſ���
		{
			pos=i;
			break;
		}
	}
	return pos;//�����±�
}

void closeaccount()
{
	system("cls");
	printf("��ӭʹ��ATM����ϵͳ\n");
	int accNUm;//����
	int pos;
	int userAnswer;
	int answer;
	char wrd[20]={0};
	printf("��������Ҫ�������˺�\n");
	scanf("%d",&accNUm);
	printf("��������˺�����\n");
	scanf("%s",wrd);
	pos=searchAccoun(accNUm);
	if(pos==0)
	{
		printf("���Ų����ڣ�������ѡ����Ҫ�����ҵ��\n");
		Chinese();
	}
	else
	{
		if(strcmp(user[pos].password,wrd)!=0)
		{
			printf("������������\n");
			printf("��1����ҵ�񣬰��������ַ��������棡\n");
			scanf("%d",&answer);
			if(answer==1)
			{
				closeaccount();
			}
			else
			{
				Chinese();
			}
		}
		else
		{
			printf("ȷʵע�����˻���\n");
			printf("��1�����������������˳��˽���!\n");
			scanf("%d",&userAnswer);
			if(userAnswer==1)
			{
				user[pos].money=0;
				strcpy(user[pos].flag,"����");
				printf("�����ɹ�������������أ�");
				fflush(stdin);//���������
				getchar();//���������
				system("cls");
				exit(0);
			}
			else
			{
				printf("����ȡ�������������������\n");
				fflush(stdin);//���������
				getchar();//���������
				system("cls");
			}
		}
	}
}
//�ҵ�����1�����򷵻�0 
int findAccount(Account a)
{
	for(int i=0;i<userCount;i++)
	{	
		if((user[i].zh==a.zh)&&(strcmp(user[i].password,a.password)==0))
		{
			curAccountIndex=i;
			return 1;
		}
	}
	return 0;
}






void updatePassword()
{
	printf("�����������:\n");
	char oldPassword[100]={'\0'};

	scanf("%s",oldPassword);
	if(strcmp(oldPassword,user[curAccountIndex].password)==0)
	{
		//�����޸� 
		printf("�����������룺\n");
		scanf("%s",user[curAccountIndex].password);
		system("cls");
		printf("�޸ĳɹ���\n");		

	}
	else
	{
		printf("�������������\n");
	} 

}




void saveMoney()
{

    printf("*******************************************\n\n");
	printf("            �ѽ��������!\n\n");
    printf("*******************************************\n\n");

	printf("���������\n");
	float money;
	scanf("%f",&money);
	system("cls");
	user[curAccountIndex].money+=money;
	printf("���ɹ���\n");
	printf("��ǰ���Ϊ:%f\n",user[curAccountIndex].money);

    
}


void saveTransactionRecord()
{
	FILE* fp=fopen("D:/transation_record.txt","w");
	TR* curP=trHead;
	while(curP!=NULL)
	{
		fprintf(fp,"%s %ld %d %f\n",curP->username,curP->timestamp,curP->type,curP->amount);
		curP=curP->next;
	}
	fclose(fp);
}  



void drawMoney()
{
    printf("*******************************************\n\n");
	printf("           �ѽ���ȡ��ҳ��!\n\n");
    printf("*******************************************\n\n");

	printf("������ȡ���");

	int money;
	scanf("%d",&money);
	system("cls");
	if(user[curAccountIndex].money<money)
	{
		printf("����!\n");
	}
	else
	{
		printf("ȡ��ɹ�!\n");
	}

	user[curAccountIndex].money-=money;
	printf("��ǰ���Ϊ:%f\n",user[curAccountIndex].money);

	
}
void Chinese()
{		
		printf("*******************************************************\n");
		printf("\t�ѽ������ҳ�棬��ѡ��������Ҫ�Ĳ�����\n");
		printf("  1.�޸�����  2.���  3.ȡ��  4.ת��  5.����  6.�˳�\t\n");
		printf("*******************************************************\n");
}



void showMenu()
{
    	int j;

		while(1)
		{	
		Chinese();
		scanf("%d",&j);
	    switch(j)
		{
		case 1:updatePassword();break;
		case 2:saveMoney();break;
		case 3:drawMoney();break;
		case 4:Transfer();break;
		case 5:closeaccount();break;
		case 6:exit();break;
		}
		if(j==6)
			break;
		}
	    printf("\n");
}


int findOtherAccount(int otherUsername)
{
	for(int i=0;i<userCount;i++)
	{
		if(user[i].zh==otherUsername)
		{
			otherAccountIndex=i;
			return 1;
		}
	}

	system("pause");
	return 0;


}



void homePage()
{
	system("cls");
    showMenu();

}



int order=0;


void signIn()
{		
		Account a; 
        printf("*******************************************\n\n");
		printf("             ��ӭ��¼\n\n");
        printf("*******************************************\n\n");
	
		printf("-----�������˺ţ�-----\n");
		scanf("%d",&a.zh);
		
		printf("-----���������룺-----\n");
		scanf("%s",a.password);
		if(findAccount(a))
		{
			homePage();
			return;
		}
		else
		{
			printf("��¼ʧ��!\n");
		}

}

void signUp1()
{
	printf("������������\n");
	scanf("%s",user[userCount].username);

	printf("���������룺\n");
	scanf("%s",user[userCount].password);

    user[userCount].zh = 1000 + userCount;
	system("cls");

	printf("-----��ϲ��,�����ɹ�!-----\n\n\n");

	printf("-----�����˺��ǣ�%d-----\n\n\n\n",user[userCount].zh);

	user[userCount].money=0.0f;

	userCount++;
	signIn();
	
}

void signUp()
{

	printf("-----��ӭʹ��ATM���й���ϵͳ,ף��ʹ����죡-----\n\n");
	printf("*******************************************\n\n");
	printf("\t-----��ѡ��ȷ����Ĳ���-----��\n");
    printf("\t1.�����˻�  2.��¼  3.�˳�\n\n");
    printf("*******************************************\n\n");

	
	int m;
	scanf("%d",&m);
	if(m==1)
	{
		signUp1();
	}
	else if(m==2)
	{
		signIn();
	}
	else if(m==3)
	{
		exit(0);
	}
}




void Transfer()
{
	int otherUsername;

	//����Է��˻�
	printf("-----������Է��˻���-----\n");
	
	scanf("%d",&otherUsername);

	//��֤�˺ŵĺϷ���
	if(findOtherAccount(otherUsername))
	{
		int money;

		//����ת�˽��
		printf("-----������ת�˽�-----\n");
		
		scanf("%d",&money);

		//��֤���Ϸ���
		if((user[curAccountIndex].money)>=money)
		{
			//��¼ת�˼�¼��ת��(�������׼�¼��㣬��ʼ������ӵ�����)
			TR * newNodeOut=(TR*)malloc(sizeof(TR));

			//ת�ˣ�ԭ�˻���Ǯ���٣��Է��˻���Ǯ���ࣩ
			user[curAccountIndex].money-=money;
			user[otherAccountIndex].money+=money;

			//�����ʾת�˳ɹ�
			system("cls");
			printf("-----ת�˳ɹ���-----\n");

			printf("-----��ǰ�˻����Ϊ%f\n-----",user[curAccountIndex].money);
			printf("-----�Է��˻����Ϊ%f\n-----",user[otherAccountIndex].money);



			
		
			newNodeOut->next=NULL;
			strcpy(newNodeOut->username,user[curAccountIndex].username);
			newNodeOut->type=2;
			newNodeOut->amount=money;
			newNodeOut->timestamp=time(NULL);
			
			if(trHead==NULL)
			{
				trHead=newNodeOut;
				trTail=newNodeOut; 
			}
			else
			{
				trTail->next=newNodeOut;
				trTail=newNodeOut;
			}


			//��¼ת�˼�¼��ת��
			TR * newNodeIn=(TR*)malloc(sizeof(TR));
		
			newNodeIn->next=NULL;
			strcpy(newNodeIn->username,user[curAccountIndex].username);
			newNodeIn->type=3;
			newNodeIn->amount=money;
			newNodeIn->timestamp=time(NULL);
			
			if(trHead==NULL)
			{
				trHead=newNodeIn;
				trTail=newNodeIn; 
			}
			else
			{
				trTail->next=newNodeIn;
				trTail=newNodeIn;
			}
		}
		else
		{
			printf("-----����!-----\n");
		}
	}
	else
	{
		system("cls");
		printf("-----�˻�����-----\n");
	}
	
}






int loadData()
{
	FILE* fp=fopen("D:/atm.txt","r");
	if(fp==NULL)
	{
		return 0; 
	}
	else
	{
		while(!feof(fp))
		{
			fscanf(fp,"%d %s %f\n",&user[userCount].zh,user[userCount].password,&user[userCount].money);
			userCount++;
		}
		return 1;
	}

}

void saveData()
{
	FILE * fp=fopen("D://atm.txt","w");
	for(int i=0;i<userCount;i++)
	{
		fprintf(fp,"%d %s %f\n",user[i].zh,user[i].password,user[i].money);
	}
	fclose(fp);
}
void exit()
{
	system("cls");
	printf("******************************\n");
	printf("-----��лʹ��ATM���й���ϵͳ-----\n");
	printf("   -----��ӭ�´�ʹ��-----\n");
	printf("******************************\n");
}
int main()
{
	int status=loadData();
	if(status==1)
	{
		printf("\n");
	}
	else
	{
		printf("����ʧ�ܣ�\n");
	}

    time_t timestamp=time(NULL);
	char * ct=ctime(& timestamp);
    printf("  ����ʱ��:%s\n",ct);
	signUp();
	saveData();
	system("pause");
	return 0;
}
