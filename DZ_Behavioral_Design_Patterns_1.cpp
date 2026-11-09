#include <iostream>
#include <string>
#include <fstream>

class LogCommand {
public:
	virtual ~LogCommand() = default;
	virtual void print(const std::string& message) = 0;
};

class ConsoleLogCommand : public LogCommand {
public:
	void print(const std::string& message) override {
		std::cout << "[Console Log]: " << message << std::endl;
	}
};

void print(LogCommand& command, const std::string& message) {
	command.print(message);

}

class FileLogCommand : public LogCommand {
private:
	std::string file_path;

public:
	explicit FileLogCommand(const std::string& path) : file_path(path) {}

	void print(const std::string& message) override {
		std::ofstream file(file_path, std::ios::app);
		if (file.is_open()) {
			file << message << std::endl;
		}


	}
};

	int main() {
		ConsoleLogCommand console_cmd;
		print(console_cmd, "Hello, Command Pattern!");

		FileLogCommand file_cmd("log.txt");
		print(file_cmd, "Hello, File!");

		return 0;
	}
