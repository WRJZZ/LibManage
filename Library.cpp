#include "iostream"
#include "Library.h"
#include <algorithm>
#include "Book.h"
#include "Reader.h"
#include <fstream>
//身份菜单
void Library::ShowMenu() {
    std::cout << "==========================欢迎使用图书管理系统：==========================" << std::endl;
    std::cout << "                              1.管理员" << std::endl;
    std::cout << "                              2.学生" << std::endl;
    std::cout << "                              0.退出系统" << std::endl;
}

//管理者菜单
void Library::ShowManagerMenu() {
    std::cout << "==========================欢迎进入图书馆后台管理系统：==========================" << std::endl;
    std::cout << "                              1.新书录入" << std::endl;
    std::cout << "                              2.删除图书" << std::endl;
    std::cout << "                              3.修改图书" << std::endl;
    std::cout << "                              4.图书查询" << std::endl;
    std::cout << "                              5.图书列表" << std::endl;
    std::cout << "                              6.借阅记录" << std::endl;
    std::cout << "                              7.新增用户" << std::endl;
    std::cout << "                              8.删除用户" << std::endl;
    std::cout << "                              9.用户列表" << std::endl;
    std::cout << "                              0.退出登录" << std::endl;
}

//学生菜单
void Library::ShowStudentMenu() {
    std::cout << "==========================欢迎进入图书馆前台管理系统：==========================" << std::endl;
    std::cout << "                              1.图书列表" << std::endl;
    std::cout << "                              2.图书查询" << std::endl;
    std::cout << "                              3.借书" << std::endl;
    std::cout << "                              4.还书" << std::endl;
    std::cout << "                              5.罚款缴纳" << std::endl;
    std::cout << "                              6.借阅记录" << std::endl;
    std::cout << "                              7.注册账户" << std::endl;
    std::cout << "                              0.退出登录" << std::endl;
}

// 实现Library类的成员函数
// 增加新图书
void Library::addBook() {
    std::string title;
    std::string author;
    std::string isbn;
    double price;
    std::string publisher;
    std::string field;
    std::cout << "书名  作者  图书编号  单价  出版社  专业领域" << std::endl;
    std::cin >> title >> author >> isbn >> price >> publisher >> field;
    Book newBook(title, author, isbn, price, publisher, field);
    books.push_back(newBook);
}

// 删除指定ISBN的图书
void Library::removeBook() {
    std::cout << "请输入你要删除的图书编号:";
    std::string isbn;
    std::cin >> isbn;
    for (auto it = books.begin(); it != books.end(); ++it) {
        if (it->isbn == isbn) {
            books.erase(it);
            std::cout << "图书编号为" << isbn << "的图书已被删除";
            break;
        }
        if (it == books.end()) {
            // 如果迭代器到达了向量的末尾，说明没有找到匹配的ISBN
            std::cout << "没有找到编号为 " << isbn << " 的图书。" << std::endl;
        }
    }
}

// 更新图书信息
void Library::updateBook() {
    std::cout << "请输入你所要更新的图书编号：";
    std::string isbn;
    std::cin >> isbn;

    // 从用户那里获取新的图书信息
    std::cout << "请输入编号为" << isbn << "的图书的新价格：";
    double newprice;
    std::cin >> newprice;
    for (auto &b: books) {
        if (b.isbn == isbn) {
            b.set_price(newprice); // 替换旧信息
            std::cout << "图书信息更新成功。" << std::endl;
            return;
        }
    }
    // 如果没有找到，抛出异常
    throw std::runtime_error("没有找到编号为 " + isbn + " 的图书。");
}

// 条件查询菜单
void Library::SearchBook() {
    // system("cls");
    int temp = 1;
    while (temp) {
        std::cout << "==========================请选择查询方式：==========================" << std::endl;
        std::cout << "                           1.作者" << std::endl;
        std::cout << "                           2.专业领域" << std::endl;
        std::cout << "                           0.退出查询" << std::endl;
        std::cout << "请选择查询方式：";
        std::cin >> temp;
        switch (temp) {
            case 1: this->searchByAuthor();
                break; //按作者查询
            case 2: this->searchByField();
                break; //按专业查询
            case 0: std::cout << "退出查询" << std::endl;
                break;
            default: std::cout << "没有此查询方式";
                break;
        }
    }
}

//按作者查询
void Library::searchByAuthor() {
    std::string author;
    std::cout << "请输入你所要查询图书的作者名：";
    std::cin >> author;
    std::vector<Book> result;
    copy_if(books.begin(), books.end(), back_inserter(result), [&author](const Book &book) {
        return book.author == author;
    });
    for (const auto &book: result) {
        std::cout << "title: " << book.get_title() << ", author: " << book.get_author() << ", ISBN: " << book.get_isbn()
                << ", price: " << book.get_price() << ", field: " << book.get_field() << ", publisher: " << book.
                get_publisher() << std::endl;
    }
}

//按专业查询
void Library::searchByField() {
    std::string field;
    std::cout << "请输入你所要查询图书的专业领域：";
    std::cin >> field;
    std::vector<Book> result;
    copy_if(books.begin(), books.end(), back_inserter(result), [&field](const Book &book) {
        return book.field == field;
    });
    for (const auto &book: result) {
        std::cout << "title: " << book.get_title() << ", author: " << book.get_author() << ", ISBN: " << book.get_isbn()
                <<
                ", price: " << book.get_price() << ", field: " << book.get_field() << ", publisher: " << book.
                get_publisher() << std::endl;
    }
}

// 列出所有图书
void Library::listBooks() const {
    std::cout << "图书列表：" << std::endl;
    std::cout << "|  序号   |     书名      |    作者     |   领域   |   ISBN   |   价格  |" << std::endl;
    for (size_t i = 0; i < books.size(); ++i) {
        const Book &book = books[i];
        std::cout << "|    " << i + 1 << "   |   " << book.title << "   |   " << book.author << "   |   " << book.field
                << "   |   " << book.isbn << "   |   " << book.price << "   |   " << std::endl;
    }
}

// 借书
void Library::borrowBook() {
    std::string studentId;
    std::cout << "学生ID:";
    std::cin >> studentId;
    std::string isbn;
    std::cout << "图书编号:";
    std::cin >> isbn;

    auto itReader = std::find_if(readers.begin(), readers.end(), [&studentId](const Reader &reader) {
        return reader.studentId == studentId;
    });

    if (itReader == readers.end()) {
        std::cout << "未找到读者" << std::endl;
        return;
    }

    if (itReader->loans.size() >= Reader::MAX_BORROWED_BOOKS) {
        std::cout << "已达到借书上限" << std::endl;
        return;
    }

    if (itReader->fines > 0) {
        std::cout << "您有未付清的罚款，无法借书" << std::endl;
        return;
    }

    auto itBook = std::find_if(books.begin(), books.end(), [&isbn](const Book &book) {
        return book.isbn == isbn && book.isAvailable;
    });

    if (itBook == books.end()) {
        std::cout << "图书不可借或不存在" << std::endl;
        return;
    }

    // 借书逻辑
    itBook->isAvailable = false;
    itBook->borrowerId = studentId;
    itBook->borrowedDate = static_cast<int>(time(nullptr)); // 获取当前时间戳
    itReader->loans.push_back(*itBook); // 添加到读者的借阅列表

    std::cout << "借阅成功" << std::endl;
}

// 还书
void Library::returnBook() {
    std::string studentId;
    std::cout << "学生ID:";
    std::cin >> studentId;
    std::string isbn;
    std::cout << "图书编号:";
    std::cin >> isbn;

    auto itReader = std::find_if(readers.begin(), readers.end(), [&studentId](const Reader &reader) {
        return reader.studentId == studentId;
    });

    if (itReader == readers.end()) {
        std::cout << "未找到读者" << std::endl;
        return;
    }
    //遍历所有现存的图书
    auto all_Book = std::find_if(books.begin(), books.end(), [&isbn](const Book &book) {
        return book.isbn == isbn;
    });
    if (all_Book == books.end()) {
        std::cout << "未找到图书" << std::endl;
        return;
    }
    //遍历读者借阅的所有图书
    auto loan_Book = std::find_if(itReader->loans.begin(), itReader->loans.end(), [&isbn](const Book &book) {
        return book.isbn == isbn;
    });
    if (loan_Book == itReader->loans.end()) {
        std::cout << "该书已归还" << std::endl;
        return;
    }
    // 计算罚款
    int daysBorrowed = static_cast<int>(time(nullptr)) / (24 * 3600) - (loan_Book->borrowedDate / (24 * 3600));
    if (daysBorrowed > Reader::MAX_BORROW_DAYS) {
        itReader->fines += (daysBorrowed - Reader::MAX_BORROW_DAYS) * Reader::FINE_PER_DAY;
    }

    // 还书逻辑
    all_Book->isAvailable = true;
    all_Book->borrowerId.clear();
    all_Book->borrowedDate = 0;

    // 从读者的借阅列表中移除图书
    itReader->loans.erase(std::remove_if(itReader->loans.begin(), itReader->loans.end(), [&isbn](const Book &book) {
        return book.isbn == isbn;
    }), itReader->loans.end());

    std::cout << "归还成功" << std::endl;
    if (itReader->fines > 0) {
        std::cout << "请注意，您有未付清的罚款，金额为：" << itReader->fines << " 元。" << std::endl;
    }
}

// 缴纳罚款
void Library::payFine() {
    std::string studentId;
    int amount;

    // 获取读者ID和罚款金额
    std::cout << "请输入学生ID：";
    std::cin >> studentId;
    std::cout << "请输入缴纳的罚款金额：";
    std::cin >> amount;

    auto itReader = std::find_if(readers.begin(), readers.end(), [&studentId](const Reader &reader) {
        return reader.studentId == studentId;
    });

    if (itReader == readers.end()) {
        std::cout << "未找到读者" << std::endl;
        return;
    }

    if (amount <= 0 || amount > itReader->fines) {
        std::cout << "罚款金额不正确" << std::endl;
        return;
    }

    itReader->fines -= amount;
    std::cout << "罚款缴纳成功，剩余罚款金额为：" << itReader->fines << " 元。" << std::endl;
}

//查询借阅记录
void Library::getReaderLoans() {
    std::string studentId;
    std::cout << "请输入你所要查询的学生ID:";
    std::cin >> studentId;
    const auto itReader = std::find_if(readers.begin(), readers.end(), [&studentId](const Reader &reader) {
        return reader.studentId == studentId;
    });

    if (itReader != readers.end()) {
        // 找到读者，打印借阅图书列表
        std::cout << "读者 " << studentId << " 借阅的图书列表如下：" << std::endl;
        for (const auto &bookName: itReader->loans) {
            std::cout << bookName << std::endl; // 使用重载的 << 运算符打印 Book 对象
        }
        std::cout << "_____________________________________" << std::endl;
    } else {
        // 没有找到读者
        std::cout << "没有找到读者ID为 " << studentId << " 的借阅记录。" << std::endl;
    }
}

// 注册读者
void Library::registerReader() {
    // 获取读者信息
    std::string id, name, gender;
    std::cout << "输入读者| ID | 姓名 | 性别 " << std::endl;
    std::cout << "      ：";
    std::cin >> id >> name >> gender;


    // 创建一个新的 Reader 对象
    Reader newReader(name, gender, id);

    // 检查读者是否已经注册
    auto it = std::find_if(readers.begin(), readers.end(),
                           [&newReader](const Reader &r) { return r.studentId == newReader.studentId; });
    // 如果读者未注册，则添加到读者列表中
    if (it == readers.end()) {
        readers.push_back(newReader);
        std::cout << "注册成功." << std::endl;
    } else {
        // 如果读者已注册，可以在这里处理，例如打印消息
        std::cout << "ID为" << newReader.studentId << "的读者已经存在." << std::endl;
    }
}

//删除读者
void Library::unregisterReader() {
    std::cout << "请输入你所要删除的读者ID:";
    std::string studentId;
    std::cin >> studentId;
    const auto it = std::remove_if(readers.begin(), readers.end(), [&studentId](const Reader &r) {
        return r.studentId == studentId;
    });
    if (it != readers.end()) {
        readers.erase(it, readers.end()); // 删除读者
        std::cout << "ID为 " << studentId << " 的读者已成功删除。" << std::endl;
    } else {
        std::cout << "没有找到ID为 " << studentId << " 的读者。" << std::endl;
    }
}

// 输出已经注册的读者列表
void Library::printReaders() {
    if (readers.empty()) {
        std::cout << "没有读者." << std::endl;
        return;
    }
    std::cout << "已经注册的用户有:" << std::endl;
    std::cout << "——————————————————————————— " << std::endl;
    std::cout << "|  姓名  |性别|    ID   | " << std::endl;
    for (const auto &reader: readers) {
        std::cout << "| " << reader.name << " | " << reader.gender << " | " << reader.studentId << " |" << std::endl;
    }
    std::cout << "——————————————————————————— " << std::endl;
}

// ... 其他成员函数的实现 ...

// 将图书和读者信息保存到文件
void Library::saveData() const {
    std::ofstream booksFile("books.dat", std::ios::out);
    std::ofstream readersFile("readers.dat", std::ios::out);

    if (!booksFile.is_open() || !readersFile.is_open()) {
        // 处理文件打开失败的情况
        return;
    }

    // 保存图书信息
    for (const auto &book: books) {
        book.save(booksFile);
    }

    // 保存读者信息
    for (const auto &reader: readers) {
        reader.save(readersFile);
    }

    booksFile.close();
    readersFile.close();
}

// 从文件加载图书和读者信息
void Library::loadData() {
    std::ifstream booksFile("books.dat", std::ios::in);
    std::ifstream readersFile("readers.dat", std::ios::in);

    if (!booksFile.is_open() || !readersFile.is_open()) {
        // 处理文件打开失败的情况
        return;
    }

    // 清空现有数据
    books.clear();
    readers.clear();

    // 加载图书信息
    Book book;
    while (book.load(booksFile)) {
        books.push_back(book);
    }

    // 加载读者信息
    Reader reader;
    while (reader.load(readersFile)) {
        readers.push_back(reader);
    }

    booksFile.close();
    readersFile.close();
}
