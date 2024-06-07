#pragma once
class Printer {
public:
    void print(std::string text) {
        std::cout << "打印：" << text << std::endl;
    }
};

// 文件读取器类
class FileReader {
public:
    std::string read(std::string filename) {
        std::cout << "读取文件：" << filename << std::endl;
        // 省略具体实现
        return "";
    }
};

void testSingleDuty() {
    FileReader reader;
    Printer printer;

    std::string filename = "test.txt";
    std::string content = reader.read(filename);
    printer.print(content);
    return;
}