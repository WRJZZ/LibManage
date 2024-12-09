#ifndef BOOK_H
#define BOOK_H
#include <ostream>
#include <string>

class Book {
public:
    // 构造函数
    Book() {
    }

    Book(std::string t, std::string a, std::string i, double p, std::string pub, std::string f)
        : title(t), author(a), isbn(i), price(p), publisher(pub), field(f), isAvailable(true) {
    }

    //Getter and Setter
    std::string get_title() const {
        return title;
    }

    void set_title(const std::string &title) {
        this->title = title;
    }

    std::string get_author() const {
        return author;
    }

    void set_author(const std::string &author) {
        this->author = author;
    }

    std::string get_isbn() const {
        return isbn;
    }

    void set_isbn(const std::string &isbn) {
        this->isbn = isbn;
    }

    double get_price() const {
        return price;
    }

    void set_price(double price) {
        this->price = price;
    }

    std::string get_publisher() const {
        return publisher;
    }

    void set_publisher(const std::string &publisher) {
        this->publisher = publisher;
    }

    std::string get_field() const {
        return field;
    }

    void set_field(const std::string &field) {
        this->field = field;
    }

    //往文件中存储信息
    void save(std::ofstream &file) const;

    //从文件中加载信息
    bool load(std::ifstream &file);

    friend std::ostream &operator<<(std::ostream &os, const Book &book);

    std::string title; // 书名
    std::string author; // 作者
    std::string isbn; // 图书编号
    double price; // 单价
    std::string publisher; // 出版社
    std::string field; // 专业领域
    bool isAvailable = false; // 存在状态（是否可借）
    // 新增借阅信息
    std::string borrowerId; // 借阅者学号
    int borrowedDate = 0; // 借书日期（可以用日期类的对象，这里简化为整数表示天数）
};

#endif // BOOK_H
