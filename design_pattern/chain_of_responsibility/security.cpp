#include <iostream>
#include <string>
#include <vector>

class SecurityCheck {
public:
    virtual void check(const std::string& file) = 0;
};

class FileExtensionCheck : public SecurityCheck {
public:
    void check(const std::string& file) override {
        if (file.find(".exe") != std::string::npos ||
            file.find(".dll") != std::string::npos ||
            file.find(".bat") != std::string::npos) {
            std::cout << "File extension not allowed!" << std::endl;
            return;
        }

        std::cout << "File extension check passed." << std::endl;
    }
};

class FileSizeCheck : public SecurityCheck {
public:
    void check(const std::string& file) override {
        if (file.length() > 1024 * 1024) {
            std::cout << "File size too big!" << std::endl;
            return;
        }

        std::cout << "File size check passed." << std::endl;
    }
};

class VirusScanCheck : public SecurityCheck {
public:
    void check(const std::string& file) override {
        std::cout << "Scanning for viruses..." << std::endl;
        // perform virus scan here

        std::cout << "Virus scan check passed." << std::endl;
    }
};

class SecurityCheckSystem {
public:
    void addCheck(SecurityCheck* check) {
        checks.push_back(check);
    }

    void runChecks(const std::string& file) {
        for (SecurityCheck* check : checks) {
            check->check(file);
        }
    }

private:
    std::vector<SecurityCheck*> checks;
};

int main() {
    SecurityCheckSystem system;
    system.addCheck(new FileExtensionCheck());
    system.addCheck(new FileSizeCheck());
    system.addCheck(new VirusScanCheck());

    std::string filename = "example.txt";
    system.runChecks(filename);

    return 0;
}