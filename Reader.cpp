#include "Reader.h"
#include "Book.h"
#include <fstream>

int Reader::MAX_BORROWED_BOOKS = 10; // 最大借书数量
int Reader::MAX_BORROW_DAYS = 60; // 最大借阅天数
int Reader::FINE_PER_DAY = 1.0;
// 实现Reader类的成员函数
// 例如，增加借书记录的函数
void Reader::borrowBook(Book &book) {
    if (loans.size() < 10) {
        // 借书数量不超过10本
        loans.push_back(book);
        book.isAvailable = false;
    } else {
        // 处理借书数量超限的情况
    }
}

// 实现归还图书的函数
void Reader::returnBook(const std::string &isbn) {
    // 找到并归还图书
    for (auto it = loans.begin(); it != loans.end(); ++it) {
        if (it->isbn == isbn) {
            it->isAvailable = true;
            loans.erase(it);
            break;
        }
    }
}

void Reader::save(std::ofstream &file) const {
    file << name << std::endl;
    file << gender << std::endl;
    file << studentId << std::endl;
    file << fines << std::endl;
    file << loans.size() << std::endl; // 保存借阅图书的数量
    for (const auto &book: loans) {
        book.save(file); // 递归保存每本书的信息
    }
}

bool Reader::load(std::ifstream &file) {
    std::getline(file, name);
    if (file.fail()) return false;

    std::getline(file, gender);
    if (file.fail()) return false;

    std::getline(file, studentId);
    if (file.fail()) return false;

    file >> fines;
    if (file.fail()) return false;
    file.ignore(); // 忽略换行符

    size_t loanCount;
    file >> loanCount;
    if (file.fail()) return false;
    file.ignore(); // 忽略换行符

    loans.clear();
    for (size_t i = 0; i < loanCount; ++i) {
        Book book;
        if (!book.load(file)) {
            // 检查每本书是否成功加载
            return false; // 如果加载失败，则返回 false
        }
        loans.push_back(book);
    }

    // 如果所有读取操作都成功，则返回 true
    return true;
}
