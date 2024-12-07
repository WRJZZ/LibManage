#ifndef LIBRARY_H
#define LIBRARY_H
#include <vector>
#include "Book.h"
#include "Reader.h"

class Library {
public:
    // -----菜单-----
    //身份菜单
    static void ShowMenu();

    //管理者菜单
    static void ShowManagerMenu();

    //学生菜单
    static void ShowStudentMenu();

    // ---图书管理函数---
    // 新增图书
    void addBook();

    // 删除图书
    void removeBook();

    // 更新图书信息
    void updateBook();

    // 查询函数
    // 条件搜索
    void SearchBook();

    //按作者查询
    void searchByAuthor();

    //按专业查询
    void searchByField();

    // 图书列表
    void listBooks() const;

    // ---读者管理函数---
    // 新增读者
    void registerReader();

    //删除读者
    void unregisterReader();

    // 输出已经注册的读者列表
    void printReaders();


    // 借还书函数
    void borrowBook();

    void returnBook();

    //缴纳罚款
    void payFine();

    //查询借阅记录
    void getReaderLoans();

    // 其他查询函数

    // 数据持久化函数
    void saveData() const;

    void loadData();

    std::vector<Book> books; // 图书列表
    std::vector<Reader> readers; // 读者列表
    // 其他数据持久化函数
};
#endif //LIBRARY_H
