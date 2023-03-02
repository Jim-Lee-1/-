/*
�������ƣ�ѧ���ɼ�����ϵͳ
����Ҫ��¼��ѧ���ɼ�
		  �޸�ѧ���ɼ�
		  ͳ��ÿ��ѧ�����ּܷ�ƽ����
		  �ܸ���ѧ����ƽ���ɼ�����
		  ��ѯѧ���ɼ�
		  ���ѧ���ɼ���
		  �ܹ�����ѧ���ɼ���ʵ���ļ��Ķ�д
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NAME_LEN 10
#define FILE_NAME "ѧ���ɼ�.txt"

typedef struct {
	char name[NAME_LEN + 1];//����
	int number;				//ѧ��
	int chinese;			//����
	int math;				//��ѧ
	int english;			//Ӣ��
	int average;			//ƽ����
	int sum;				//�ܷ�
} student;					//���ڴ洢����ѧ������Ϣ

typedef struct node {
	student stu;		//�����򣬴洢ѧ����Ϣ
	struct node *next;	//ָ����ָ����һ���ڵ�
} studentNode;			//ѧ���ڵ�

typedef struct {
	studentNode *head;	//ͷָ��
	studentNode *tail;	//βָ��
	int count;			//ѧ���ڵ�����
} studentList;			//ѧ������

void initialize(studentList *L);//��ʼ������,����ͷ�ڵ�
void enter(studentList *L);		//¼������
void display(studentList *L);	//�������
void find(studentList *L);		//����ĳ�ڵ�
void modify(studentList *L);	//�޸�ĳ�ڵ�
void sort(studentList *L);		//�������½������
void write(studentList *L);		//д���ļ�����д���ͷſռ�
void read(studentList *L);		//��ȡ�ļ����߶��߽���

int main() {
	//��������
	printf("		**************ѧ���ɼ�����ϵͳ**************\n");
	printf("		*  1.¼���µ�ѧ���ɼ�                      *\n");
	printf("		*  2.�������޸�ѧ���ɼ�                    *\n");
	printf("		*  3.��������ѯѧ���ɼ�                    *\n");
	printf("		*  4.���ȫ��ѧ���ĳɼ�                    *\n");
	printf("		*  5.��ƽ�������ѧ���ɼ�                  *\n");
	printf("		*  6.�˳�ѧ���ɼ�����ϵͳ                  *\n");
	printf("		********************************************\n");
	printf("  	                                                \n");
	//����ѧ������
	studentList *L = (studentList *)malloc(sizeof(studentList));
	//��ʼ��ѧ������
	initialize(L);
	//���ļ����ȡ���ݵ�����
	read(L);
	//������������һ������ѭ����һ��switchд��
	while (1) {
		int code;
		printf("������������еĲ�����Ӧ������: ");
		scanf("%d", &code);
		switch (code) {
			case 1:
				enter(L);
				break;
			case 2:
				modify(L);
				break;
			case 3:
				find(L);
				break;
			case 4:
				display(L);
				break;
			case 5:
				sort(L);
				break;
			case 6:
				write(L);
				free(L->head);	//ͷ�ڵ㱻����
				free(L);		//��������
				return 0;
			default:
				printf("%d����Ч�����֣����������룡\n\n", code);
				break;
		}
	}
	return 0;
}

void initialize(studentList *L) {
	//����ͷ�ڵ�
	studentNode *s = (studentNode *)malloc(sizeof(studentNode));
	s->next = NULL;
	//��ʼ������
	//ͷβָ���ָ��ͷ�ڵ㣬��ʼ����Ϊ��
	L->head = s;
	L->tail = s;
	L->count = 0;
}

void enter(studentList *L) {
	//�����½ڵ�
	studentNode *s = (studentNode *)malloc(sizeof(studentNode));
	//������Ϣ���浽�½ڵ���
	printf("������ѧ��������");
	scanf("%s", s->stu.name);
	printf("������ѧ��ѧ�ţ�");
	scanf("%d", &s->stu.number);
	printf("���������ĳɼ���");
	scanf("%d", &s->stu.chinese);
	printf("��������ѧ�ɼ���");
	scanf("%d", &s->stu.math);
	printf("������Ӣ��ɼ���");
	scanf("%d", &s->stu.english);
	s->stu.sum = s->stu.chinese + s->stu.math + s->stu.english;
	s->stu.average = s->stu.sum / 3;
	//������Ϊ�գ���βָ��ָ���½ڵ�
	if (L->head == L->tail) {
		L->tail = s;
	}
	//���½ڵ�������ͷ����ͷ�巨��
	s->next = L->head->next;
	L->head->next = s;
	L->count++;
	//���������Ϣ
	printf("��Ϣ¼��ɹ���\n\n");
}

void display(studentList *L) {
	printf("����%d��ѧ�����ݣ�\n", L->count);
	printf("����\t\tѧ��\t\t����\t\t��ѧ\t\tӢ��\t\t�ܷ�\t\tƽ����\n");
	//����һ�ڵ�ָ��ָ��ͷ�ڵ�
	studentNode *p;
	p = L->head;
	//�����������
	while (p->next) {
		p = p->next;
		printf("%s", p->stu.name);
		printf("\t\t%d", p->stu.number);
		printf("\t\t%d", p->stu.chinese);
		printf("\t\t%d", p->stu.math);
		printf("\t\t%d", p->stu.english);
		printf("\t\t%d", p->stu.sum);
		printf("\t\t%d", p->stu.average);
		printf("\n");
	}
	printf("\n");
}

void find(studentList *L) {
	//���û�����Ҫ���ҵ�ѧ��
	printf("������ѧ��������");
	char name[NAME_LEN + 1];
	scanf("%s", name);
	//��������Ա�����
	studentNode *p = L->head->next;
	while (p) {
		//�����˾��������������
		if (strcmp(p->stu.name, name) == 0) {
			printf("����\t\tѧ��\t\t����\t\t��ѧ\t\tӢ��\t\t�ܷ�\t\tƽ����\n");
			printf("%s", p->stu.name);
			printf("\t\t%d", p->stu.number);
			printf("\t\t%d", p->stu.chinese);
			printf("\t\t%d", p->stu.math);
			printf("\t\t%d", p->stu.english);
			printf("\t\t%d", p->stu.sum);
			printf("\t\t%d", p->stu.average);
			printf("\n\n");
			return;
		}
		//���ֲ����Ͼ���һ��
		p = p->next;
	}
	//�������ﶼû�ҵ��������
	printf("û�ҵ����%s����Ϣ��\n\n", name);
}

void modify(studentList *L) {
	//���û�����Ҫ�޸ĵ�ѧ��
	printf("������ѧ��������");
	char name[NAME_LEN + 1];
	scanf("%s", name);
	//��������Ա�����
	studentNode *p = L->head->next;
	while (p) {
		//�����˾����û����¼��벢��������
		if (strcmp(p->stu.name, name) == 0) {
			printf("������������Ϣ��\n");
			printf("������ѧ��ѧ�ţ�");
			scanf("%d", &p->stu.number);
			printf("���������ĳɼ���");
			scanf("%d", &p->stu.chinese);
			printf("��������ѧ�ɼ���");
			scanf("%d", &p->stu.math);
			printf("������Ӣ��ɼ���");
			scanf("%d", &p->stu.english);
			p->stu.sum = p->stu.chinese + p->stu.math + p->stu.english;
			p->stu.average = p->stu.sum / 3;
			printf("��Ϣ�޸ĳɹ���\n\n");
			return;
		}
		//���ֲ����Ͼ���һ��
		p = p->next;
	}
	//�������ﶼû�ҵ��������
	printf("û�ҵ����%s����Ϣ��\n\n", name);
}

void sort(studentList *L) {
	//�����ڵ㶼û���Ÿ�ƨ��
	if (L->count < 2) {
		printf("����������ɣ�\n");
		display(L);
		return;
	}
	//��������
	studentNode *p, *pre, *tmp;
	//pָ��ڶ���ѧ���ڵ�
	p = L->head->next;
	//�����ͷ�ڵ�͵�һ��ѧ���ڵ㴦�Ͽ�
	L->head->next = NULL;
	//�ӵ�һ��ѧ���ڵ㿪ʼһֱ����ѭ��
	while (p) {
		//�����һ���ڵ��ָ��
		tmp = p->next;
		//�ҵ�����λ��
		pre = L->head;
		while (pre->next != NULL && pre->next->stu.average > p->stu.average)
			pre = pre->next;
		//����βָ��
		if (pre->next == NULL) {
			L->tail = p;
		}
		//����
		p->next = pre->next;
		pre->next = p;
		//������һ��
		p = tmp;
	}
	printf("����������ɣ�\n");
	display(L);
}

void write(studentList *L) {
	//���ļ���
	FILE *fp = fopen(FILE_NAME, "w");
	if (fp == NULL) {
		printf("�ļ�%s��ʧ��\n", FILE_NAME);
		exit(EXIT_FAILURE);
	}
	//��ѧ���ڵ���������ڵ�һ��
	fprintf(fp, "%d\n", L->count);
	//����һ�ڵ�ָ��ָ��ͷ�ڵ�
	studentNode *p;
	p = L->head->next;
	//��������һ��������Ϊһ�����
	while (p) {
		fprintf(fp, "%s ", p->stu.name);
		fprintf(fp, "%d ", p->stu.number);
		fprintf(fp, "%d ", p->stu.chinese);
		fprintf(fp, "%d ", p->stu.math);
		fprintf(fp, "%d ", p->stu.english);
		fprintf(fp, "%d ", p->stu.sum);
		fprintf(fp, "%d ", p->stu.average);
		fprintf(fp, "\n");
		//������֮���ͷŽڵ�ռ�
		studentNode *next = p->next;
		free(p);
		p = next;
		L->count--;
	}
	//�ر��ļ���
	fclose(fp);
	//������Ϣ
	printf("�����ѱ��棡ллʹ�ã��ټ���\n");
}

void read(studentList *L) {
	//���ļ���
	FILE *fp = fopen(FILE_NAME, "r");
	if (fp == NULL) {
		printf("�ļ�%s��ʧ��\n", FILE_NAME);
		exit(EXIT_FAILURE);
	}
	//��ȡ��һ�е�ѧ���ڵ�����
	fscanf(fp, "%d", &L->count);
	//ѭ����ȡ���ݣ�ѭ������Ϊcount
	for (int i = 1; i <= L->count; i++) {
		//�����½ڵ�
		studentNode *s = (studentNode *)malloc(sizeof(studentNode));
		//��ȡ����
		fscanf(fp, "%s ", s->stu.name);
		fscanf(fp, "%d ", &s->stu.number);
		fscanf(fp, "%d ", &s->stu.chinese);
		fscanf(fp, "%d ", &s->stu.math);
		fscanf(fp, "%d ", &s->stu.english);
		fscanf(fp, "%d ", &s->stu.sum);
		fscanf(fp, "%d ", &s->stu.average);
		//���½ڵ�������β����β�巨��
		s->next = NULL;
		L->tail->next = s;
		L->tail = s;
	}
	//�ر��ļ���
	fclose(fp);
}