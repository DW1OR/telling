#include <iostream>
#include <string>

#define MAX 100 // 最大人数

using namespace std;

// 联系人结构体
struct Person {
  // 姓名
  string name;

  // 性别：1男，0女
  int sex;

  // 年龄
  int age;

  // 电话
  string phone;

  // 住址
  string addr;
};

// 通讯录结构体
struct AddressBooks {
  // 通讯录中保存联系人的数组
  Person personList[MAX];

  // 通讯录中人员个数
  int size;
};

// 菜单页面
void mainMenu() {
  cout << "1、添加联系人" << endl;
  cout << "2、显示联系人" << endl;
  cout << "3、删除联系人" << endl;
  cout << "4、查找联系人" << endl;
  cout << "5、修改联系人" << endl;
  cout << "6、清空联系人" << endl;
  cout << "0、退出通讯录" << endl;
}

// 1、添加联系人
void addPerson(AddressBooks *abs) {
  // 判断通讯录是否已满
  if (abs->size >= MAX) {
    cout << "通讯录已满，无法添加！" << endl;
    return;
  } else {
    // 添加
    cout << "请输入新联系人的姓名：" << endl;
    cin >> abs->personList[abs->size].name;

    cout << "请输入新联系人的性别：" << endl;
    cout << "1 --- 男" << endl;
    cout << "0 --- 女" << endl;
    cin >> abs->personList[abs->size].sex;
    while (!(abs->personList[abs->size].sex == 1 ||
             abs->personList[abs->size].sex == 0) ||
           cin.fail()) {
      cout << "输入有误，请重新输入：" << endl;
      // 清空cin缓冲区
      cin.clear();
      cin.ignore();
      cin >> abs->personList[abs->size].sex;
    }

    cout << "请输入新联系人的年龄：" << endl;
    cin >> abs->personList[abs->size].age;
    // 检测输入错误
    while (cin.fail()) {
      cout << "输入有误，请重新输入：" << endl;
      // 清除错误状态标志
      cin.clear();
      // 忽略缓冲区中的无效输入
      cin.ignore();
      cin >> abs->personList[abs->size].age;
    }

    cout << "请输入新联系人的电话：" << endl;
    cin >> abs->personList[abs->size].phone;

    cout << "请输入新联系人的住址：" << endl;
    cin >> abs->personList[abs->size].addr;

    abs->size++;

    cout << "添加联系人成功！" << endl;
    system("pause");
    system("cls");
  }
}

// 2、显示所有联系人
void findPersonByList(AddressBooks *abs) {
  // 判断通讯录中人数是否为0，如果为0，提示记录为空
  // 如果部位0，显示记录的联系人信息
  if (abs->size == 0) {
    cout << "当前记录为空" << endl;
  } else {
    cout << "姓名\t性别\t年龄\t电话\t地址\t" << endl;
    for (int i = 0; i < abs->size; i++) {
      cout << abs->personList[i].name << "\t";
      cout << (abs->personList[i].sex == 1 ? "男" : "女") << "\t";
      cout << abs->personList[i].age << "\t";
      cout << abs->personList[i].phone << "\t";
      cout << abs->personList[i].addr << endl;
    }
  }

  system("pause");
  system("cls");
}

// 检测联系人数组中的位置
int isExist(AddressBooks *abs, string name) {
  for (int i = 0; i < abs->size; i++) {
    // 如果找到用户输入的姓名，返回对应的位置
    if (abs->personList[i].name == name) {
      return i;
    }
  }

  return -1;
}

// 3、删除指定联系人
void deletePerson(AddressBooks *abs) {
  cout << "请输入要删除的联系人" << endl;
  string name;
  cin >> name;

  int index = isExist(abs, name);
  if (index != -1) { // 找到对应联系人，进行删除
    for (int i = index; i < abs->size - 1; i++) {
      abs->personList[i] = abs->personList[i + 1];
    }
    abs->size--; // 更新联系人个数
    cout << "删除成功" << endl;
  } else {
    cout << "查无此人" << endl;
  }

  system("pause");
  system("cls");
}

// 4、查找联系人
void findPersonByName(AddressBooks *abs) {
  cout << "请输入要查找的联系人" << endl;
  string name;
  cin >> name;

  int index = isExist(abs, name);
  if (index != -1) { // 找到对应联系人，展示信息
    cout << "姓名\t性别\t年龄\t电话\t地址\t" << endl;
    cout << abs->personList[index].name << "\t";
    cout << (abs->personList[index].sex == 1 ? "男" : "女") << "\t";
    cout << abs->personList[index].age << "\t";
    cout << abs->personList[index].phone << "\t";
    cout << abs->personList[index].addr << endl;
  } else {
    cout << "查无此人" << endl;
  }

  system("pause");
  system("cls");
}

// 5、修改联系人
void updatePerson(AddressBooks *abs) {
  cout << "请输入要修改的联系人" << endl;
  string name;
  cin >> name;

  int index = isExist(abs, name);
  if (index != -1) { // 找到对应联系人，修改信息
    cout << "请输入修改后的联系人姓名：" << endl;
    cin >> abs->personList[index].name;

    cout << "请输入修改后的联系人性别：" << endl;
    cout << "1 --- 男" << endl;
    cout << "0 --- 女" << endl;
    cin >> abs->personList[index].sex;
    while (!(abs->personList[index].sex == 1 ||
             abs->personList[index].sex == 0) ||
           cin.fail()) {
      cout << "输入有误，请重新输入：" << endl;
      // 清空cin缓冲区
      cin.clear();
      cin.ignore();
      cin >> abs->personList[index].sex;
    }

    cout << "请输入修改后的联系人年龄：" << endl;
    cin >> abs->personList[index].age;
    // 检测输入错误
    while (cin.fail()) {
      cout << "输入有误，请重新输入：" << endl;
      // 清除错误状态标志
      cin.clear();
      // 忽略缓冲区中的无效输入
      cin.ignore();
      cin >> abs->personList[index].age;
    }

    cout << "请输入修改后的联系人电话：" << endl;
    cin >> abs->personList[index].phone;

    cout << "请输入修改后的联系人住址：" << endl;
    cin >> abs->personList[index].addr;

    cout << "修改联系人信息成功" << endl;
  } else {
    cout << "查无此人" << endl;
  }

  system("pause");
  system("cls");
}

// 6、清空所有联系人
void deleteAllPerson(AddressBooks *abs) {
  // 将联系人数量重置为0，做逻辑清空
  abs->size = 0; 
  cout << "清空所有联系人" << endl;
  system("pause");
  system("cls");
}


int main() {
  // 用户输入的选择
  int select = 0;

  // 创建通讯录变量
  AddressBooks abs;
  abs.size = 0;

  while (true) {
    // 每次循环都清屏
    // system("cls");

    // 进入主页面
    mainMenu();

    // 用户输入选择
    cout << "请输入想要访问的功能" << endl;
    cin >> select;

    switch (select) {
    case 1: // 添加联系人
      addPerson(&abs);
      break;
    case 2: // 显示联系人
      findPersonByList(&abs);
      break;
    case 3: // 删除联系人
      deletePerson(&abs);
      break;
    case 4: // 查找联系人
      findPersonByName(&abs);
      break;
    case 5: // 修改联系人
      updatePerson(&abs);
      break;
    case 6: // 清空联系人
      deleteAllPerson(&abs);
      break;
    case 0: // 退出通讯录
      cout << "正在退出通讯录..." << endl;
      system("pause");
      return 0;
      break;
    default:
      break;
    }
  }

  return 0;
}
