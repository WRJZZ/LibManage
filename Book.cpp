#include "Book.h"
#include <fstream>

void Book::save(std::ofstream &file) const {
    file << title << std::endl;
    file << author << std::endl;
    file << isbn << std::endl;
    file << price << std::endl;
    file << publisher << std::endl;
    file << field << std::endl;
    file << isAvailable << std::endl;
    file << borrowerId << std::endl;
    file << borrowedDate << std::endl;
}

bool Book::load(std::ifstream &file) {
    std::getline(file, title);
    if (file.fail()) return false;

    std::getline(file, author);
    if (file.fail()) return false;

    std::getline(file, isbn);
    if (file.fail()) return false;

    file >> price;
    if (file.fail()) return false;
    file.ignore(); // 忽略换行符

    std::getline(file, publisher);
    if (file.fail()) return false;

    std::getline(file, field);
    if (file.fail()) return false;

    file >> isAvailable;
    if (file.fail()) return false;
    file.ignore(); // 忽略换行符

    std::getline(file, borrowerId);
    if (file.fail()) return false;

    file >> borrowedDate;
    if (file.fail()) return false;
    file.ignore(); // 忽略换行符

    // 如果所有读取操作都成功，则返回 true
    return true;
}

std::ostream &operator<<(std::ostream &os, const Book &book) {
    // 输出 Book 对象的详细信息
    os << "书名: " << book.title << ", 作者: " << book.author
            << ", ISBN: " << book.isbn << ", 价格: " << book.price
            << ", 出版社: " << book.publisher << ", 专业领域: " << book.field;
    return os;
}
