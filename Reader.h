#ifndef READER_H
#define READER_H

#include <string>
#include <vector>
#include "Book.h"

class Reader {
public:
    std::string name; // 姓名
    std::string gender; // 性别
    std::string studentId; // 学号
    std::vector<Book> loans; // 借阅的图书列表
    int fines = 0; //罚款金额

    static int MAX_BORROWED_BOOKS; // 最大借书数量
    static int MAX_BORROW_DAYS; // 最大借阅天数
    static int FINE_PER_DAY; // 每天罚款金额
    // 构造函数
    Reader() {
    }

    Reader(std::string name, std::string gender, std::string stuId)
        : name(name), gender(gender), studentId(stuId) {
    }

    //往文件中存储信息
    void save(std::ofstream &file) const;

    //从文件中加载信息
    bool load(std::ifstream &file);
};


#endif // READER_H
