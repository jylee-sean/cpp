#include <iostream>
#include <string>

class Validator {
public:
    virtual void setNext(Validator* next) = 0;
    virtual void validate(std::string data) = 0;
};

class LengthValidator : public Validator {
public:
    void setNext(Validator* next) override {
        this->next = next;
    }

    void validate(std::string data) override {
		//std::cout<<"Length Validator"<<std::endl;

        if (data.length() > 20) {
            std::cout << "Data too long!" << std::endl;
            return;
        }

        if (next != nullptr) {
            next->validate(data);
        }
    }

private:
    Validator* next = nullptr;
};

class SymbolValidator : public Validator {
public:
    void setNext(Validator* next) override {
        this->next = next;
    }

    void validate(std::string data) override {
		//std::cout<<"Symbol Validator"<<std::endl;

        if (data.find_first_of("!@#$%^&*()") != std::string::npos) {
            std::cout << "Data contains forbidden symbols!" << std::endl;
            return;
        }

        if (next != nullptr) {
            next->validate(data);
        }
    }

private:
    Validator* next = nullptr;
};

class NumberValidator : public Validator {
public:
	void setNext(Validator* next) override {
		this->next = next;
	}

	void validate(std::string data) override {

		//std::cout<<"Number Validator"<<std::endl;

		if (data.find_first_of("0123456789") != std::string::npos) {
			std::cout << "Data contains numbers!" << std::endl;
			return;
		}

		if (next != nullptr) {
			next->validate(data);
		}
	}

private:
	Validator* next = nullptr;
};

int main() {

	LengthValidator *lv = new LengthValidator();
	SymbolValidator *sv = new SymbolValidator();
	NumberValidator *nv = new NumberValidator();

	lv->setNext(sv);
	sv->setNext(nv);

	Validator* validator = lv;

	validator->validate("test123");
	std::cout<<"-------"<<std::endl;
	validator->validate("test123!!!"); // Should fail length and symbol validation
	std::cout<<"-------"<<std::endl;
	validator->validate("testtesttest123"); // Should fail length validation
	std::cout<<"-------"<<std::endl;
	validator->validate("testtesttest"); // Should pass all validations

	return 0;
}