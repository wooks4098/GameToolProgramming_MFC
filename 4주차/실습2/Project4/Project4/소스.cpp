#include<stdio.h>
#include<stdlib.h>
#include<Windows.h>
#define MAX 50

typedef struct student
{
	char Name[10];
	int Age;
	int Class;
	int Number;
	char Gender[10];
}Student;

void ShowStudent(Student* St)
{
	printf("======%s학생(%d번)======\n", St->Name, St->Number);
	printf("나이 : %d,  성별 : %s,  학년 : %d\n", St->Age, St->Gender, St->Class);
	printf("======================\n");
}
void ShowStudent_Standard_Grade(Student* St, int Grade)
{
	if (St->Class == Grade)
	{
		printf("======%s학생(%d번)======\n", St->Name, St->Number);
		printf("나이 : %d,  성별 : %s,  학년 : %d\n", St->Age, St->Gender, St->Class);
		printf("======================\n");
	}
}
void SetStudent(Student* St, int* StudentCount)
{
	St->Number = ++(*StudentCount);
	printf("======%d번 학생======\n", St->Number);
	printf("이름 입력 : ");
	scanf("%s", St->Name);
	printf("나이 입력 : ");
	scanf("%d", &St->Age);
	printf("성별 입력 : ");
	scanf("%s", St->Gender);
	printf("학년 입력(1~3) : ");
	scanf("%d", &St->Class);
	while (!(St->Class >= 1 && St->Class <= 3))
	{
		printf("학년 잘못 입력 (범위 1~3 학년)\n");
		system("pause");
		printf("학년 입력(1~3) : ");
		scanf("%d", &St->Class);
	}
}

void Search_Name(Student* St, char name[], int StudentCount)
{
	if (!(strcmp(St->Name, name)))
	{
		system("cls");
		printf("======%s학생(%d번)======\n", St->Name, St->Number);
		printf("나이 : %d,  성별 : %s,  학년 : %d\n", St->Age, St->Gender, St->Class);
		printf("======================\n");
	}
}

void Student_Delete(Student* St)
{
	St = NULL;
}

void Show_Student_List_Standard_Grade(Student* St[], int Grade, int StudentCount)
{
	printf("[-------------------%d학년-------------------]\n", Grade);
	for (int i = 0; i < StudentCount; i++)
	{
		if (St[i]->Class == Grade)
		{
			ShowStudent_Standard_Grade(St[i], Grade);
		}
	}
	printf("[-------------------------------------------]\n");
}

void main()
{
	Student* Student_List[MAX];
	int Count;
	int Select;
	int StudentCount = 0;
	int Grade;
	char search_name[256];
	

	//test
	int age;
	int grade;
	char name[10] = { 0 };
	char gender[10] = { 0 };
	//test
	while (1)
	{
		system("cls");
		printf("=====학생관리프로그램=====(총 인원 : %d)\n", StudentCount);
		printf("1.학생 등록\n");
		printf("2.학생 목록(번호순)\n");
		printf("3.학생 목록(학년순)\n");
		printf("4.학년 검색\n");
		printf("5.학생 검색\n");
		printf("6.마지막 학생 삭제\n");
		printf("7.학생 전체 삭제\n");
		printf("8.학생정보 저장\n");
		printf("9.학생정보 불러오기\n");
		printf("10.종료\n");
		printf("입력 : ");
		scanf("%d", &Select);
		switch (Select)
		{
		case 1:
			system("cls");
			if (StudentCount + 1 >= MAX)
			{
				printf("학생정원(50명)이 모두 찼습니다.\n");
				system("pause");
				break;
			}
			Student_List[StudentCount] = (Student*)malloc(sizeof(Student));
			SetStudent(Student_List[StudentCount], &StudentCount);
			break;
		case 2:
			system("cls");
			for (int i = 0; i < StudentCount; i++)
			{
				ShowStudent(Student_List[i]);
			}
			system("pause");
			break;
		case 3:
			system("cls");
			Show_Student_List_Standard_Grade(Student_List, 1, StudentCount);
			Show_Student_List_Standard_Grade(Student_List, 2, StudentCount);
			Show_Student_List_Standard_Grade(Student_List, 3, StudentCount);
			system("pause");
			break;
		case 4:
			system("cls");
			printf("검색할 학년 입력(1~3) : ");
			scanf("%d", &Grade);
			while (!(Grade >= 1 && Grade <= 3))
			{
				printf("학년 잘못 입력 (범위 1~3 학년)\n");
				system("pause");
				printf("학년 입력(1~3) : ");
				scanf("%d", &Grade);
			}
			Show_Student_List_Standard_Grade(Student_List, Grade, StudentCount);
			system("pause");
			break;
		case 5:
			system("cls");
			printf("검색할 이름 입력 : ");
			scanf("%s", search_name);
			for (int i = 0; i < StudentCount; i++)
			{
				Search_Name(Student_List[i], search_name, StudentCount);
			}
			system("pause");
			break;
		case 6:
			free(Student_List[StudentCount - 1]);
			Student_List[StudentCount - 1] = NULL; // ????
			StudentCount--;
			break;
		case 7:
			for (int i = 0; i < StudentCount; i++)
			{
				free(Student_List[i]);
				Student_List[i] = NULL; //????

			}
			StudentCount = NULL;
			break;
		case 8:
		{
			FILE* f = fopen("학생정보.txt", "w");
			fprintf(f, "%d\n", StudentCount); //처음에 case문에서 파일 선언했다가 케이스문에서 하면 안됀다고 오류떠서 메인으로 올림
			for (int i = 0; i < StudentCount; i++)
			{
				fprintf(f, "%s %d %s %d\n", Student_List[i]->Name, Student_List[i]->Age, Student_List[i]->Gender, Student_List[i]->Class);//어쩔때 -> 어쩔떄.헷갈림
			}
			fclose(f);
			printf("학생 정보 저장 완료!!\n");
			system("pause");
			break;
		}
		case 9:
		{
			FILE* f = fopen("학생정보.txt", "r");
			if (f == NULL)
				printf("기록된 학생정보가 없습니다..");
			else
			{
				fscanf(f, "%d", &Count);
				while (Count)
				{
					fscanf(f, "%s", name);
					printf("%s", name);
					fscanf(f, "%d", &age);
					printf("%d", age);
					fscanf(f, "%s", gender);
					printf("%s", gender);
					fscanf(f, "%d", &grade);
					printf("%d", grade);
					StudentCount++;
					Count--;
				}
				fclose(f);
			}
			system("pause");
			break;
		}
		case 10:
			return;
		}
	}

}