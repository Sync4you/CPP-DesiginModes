#pragma once
class Printer {
public:
    void print(std::string text) {
        std::cout << "��ӡ��" << text << std::endl;
    }
};

// �ļ���ȡ����
class FileReader {
public:
    std::string read(std::string filename) {
        std::cout << "��ȡ�ļ���" << filename << std::endl;
        // ʡ�Ծ���ʵ��
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