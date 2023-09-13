#include<stdio.h>
struct Employee {
    int id; // 职工编号
    char name[20]; // 姓名
    char sex[5]; // 性别
    int age; // 年龄
    char position[20]; // 职位
    float salary; // 工资
};
int main()

{
    struct Employee employees[100] ;
    int count = 0;
    int choice, id;
    while (1) {
        printf("请选择操作：\n");
        printf("1. 添加职工信息\n");
        printf("2. 删除职工信息\n");
        printf("3. 修改职工信息\n");
        printf("4. 查询职工信息\n");
        printf("5. 退出程序\n");
        scanf_s("%d", &choice);
        switch (choice) {
        case 1:
            addEmployee(employees, &count);
            break;
        case 2:
            printf("请输入要删除的职工编号：");
            scanf_s("%d", &id);
            deleteEmployee(employees, &count, id);
            break;
        case 3:
            printf("请输入要修改的职工编号：");
            scanf_s("%d", &id);
            modifyEmployee(employees, count, id);
            break;
        case 4:
            printf("请输入要查询的职工编号：");
            scanf_s("%d", &id);
            queryEmployee(employees, count, id);
            break;
        case 5:
            printf("程序已退出！\n");
            return 0;
        default:
            printf("输入有误，请重新输入！\n");
            break;
        }
    }
    return 0;
}

// 添加职工信息
int addEmployee(struct Employee* employees, int* count) {
    printf("请输入职工编号：");
    scanf_s("%d", &employees[*count].id);
    printf("请输入职工姓名：");
    scanf_s("%s", employees[*count].name);
    printf("请输入职工性别：");
    scanf_s("%s", employees[*count].sex);
    printf("请输入职工年龄：");
    scanf_s("%d", &employees[*count].age);
    printf("请输入职工职位：");
    scanf_s("%s", employees[*count].position);
    printf("请输入职工工资：");
    scanf_s("%f", &employees[*count].salary);
    (*count)++;
}
// 删除职工信息
int deleteEmployee(struct Employee* employees, int* count, int id) {
    int i, j;
    for (i = 0; i < *count; i++) {
        if (employees[i].id == id) {
            for (j = i; j < *count - 1; j++) {
                employees[j] = employees[j + 1];
            }
            (*count)--;
            printf("删除成功！\n");
            return;
        }
    }
    printf("未找到该职工信息！\n");
}
// 修改职工信息
int modifyEmployee(struct Employee* employees, int count, int id) {
    int i;
    for (i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("请输入职工姓名：");
            scanf_s("%s", employees[i].name);
            printf("请输入职工性别：");
            scanf_s("%s", employees[i].sex);
            printf("请输入职工年龄：");
            scanf_s("%d", &employees[i].age);
            printf("请输入职工职位：");
            scanf_s("%s", employees[i].position);
            printf("请输入职工工资：");
            scanf_s("%f", &employees[i].salary);
            printf("修改成功！\n");
            return;
        }
    }
    printf("未找到该职工信息！\n");
}
// 查询职工信息
int queryEmployee(struct Employee* employees, int count, int id) {
    int i;
    for (i = 0; i < count; i++) {
        if (employees[i].id == id) {
            printf("职工编号：%d\n", employees[i].id);
            printf("职工姓名：%s\n", employees[i].name);
            printf("职工性别：%s\n", employees[i].sex);
            printf("职工年龄：%d\n", employees[i].age);
            printf("职工职位：%s\n", employees[i].position);
            printf("职工工资：%f\n", employees[i].salary);
            return;
        }
    }
    printf("未找到该职工信息！\n");
