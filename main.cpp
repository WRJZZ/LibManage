#include <iostream>
#include "Library.h"
#include "Book.h"
#include "Reader.h"

Library library;
Book book;

void Init() {
    library.loadData();
    Book newbook("我爱你中国", "author1", "a001", 50, "新华出版社", "文化");
    Book newbook1("我爱你世界", "author2", "a002", 50, "新华出版社", "文化");
    library.books.push_back(newbook);
    library.books.push_back(newbook1);

    Reader reader("邢裕婷", "女", "1314520");
    Reader reader1("纪梓喆", "男", "1314521");
    Reader reader2("薛高", "男", "23365000");
    Reader reader3("刘威辰", "男", "23365001");
;
    library.readers.push_back(reader);
    library.readers.push_back(reader1);
    library.readers.push_back(reader2);
    library.readers.push_back(reader3);
}

//管理员
void Manager() {
    int temp = 1;
    while (temp) {
        Library::ShowManagerMenu();
        std::cout << "请输入所选择的功能：";
        std::cin >> temp;
        switch (temp) {
            case 1: library.addBook();
                break; //新书录入
            case 2: library.removeBook();
                break; //删除图书
            case 3: library.updateBook();
                break; //修改图书
            case 4: library.SearchBook();
                break; //图书查询
            case 5: library.listBooks();
                break; //图书列表
            case 6: library.getReaderLoans();
                break; //借阅记录
            case 7: library.registerReader();
                break; //新增用户
            case 8: library.unregisterReader();
                break; //删除用户
            case 9: library.printReaders();
                break; //用户列表
            case 0: break; //退出登录
            default: std::cout << "没有此功能，请重新选择" << std::endl;
                break;
        }
    }
}

//管理员
void Student() {
    int temp = 1;
    while (temp) {
        Library::ShowStudentMenu();
        std::cout << "请输入所选择的功能：";
        std::cin >> temp;
        switch (temp) {
            case 1: library.listBooks();
                break; //图书列表
            case 2: library.SearchBook();
                break; //图书查询
            case 3: library.borrowBook();
                break; //借书
            case 4: library.returnBook();
                break; //还书
            case 5: library.payFine();
                break; //缴纳罚款
            case 6: library.getReaderLoans();
                break; //借阅记录
            case 7: library.registerReader();
                break; //注册账户
            case 0: break; //退出登录
            default: std::cout << "没有此功能，请重新选择：";
                break;
        }
    }
}

void System() {
    int temp = 1;
    while (temp) {
        Library::ShowMenu();
        std::cout << "请选择你的身份：";
        std::cin >> temp;
        switch (temp) {
            case 1: Manager();
                break; //管理员
            case 2: Student();
                break; //学生
            case 0: library.saveData();
                break; //向文件中存储信息并退出系统
            default: std::cout << "没有此角色，请重新选择：";
                break;
        }
    }
}

int main() {
    Init();
    System();
    return 0;
}
