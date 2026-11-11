#include <BigLogger.h>
#include <filesystem>
#include <format>

int test_simple_logs(){
    auto path = "logs/log.log";
    auto name = "    lo g  ge     r    ";

    auto full_path = std::filesystem::current_path() / path;

    biglg::BigLogger bl = biglg::BigLogger(name, path);
    if (!std::filesystem::exists(full_path)){
        throw std::runtime_error(std::format("File doesnt exists at directory: {}", full_path.string()));
    }

    std::cout << "Before setting name: " << "START" << name << "END" << std::endl;
    std::cout << "After setting name: " << "START" << bl.get_name() << "END" << std::endl;

    bl.info("Information");
    bl.warn("Warning!!!");
    bl.err("fckit...");
    bl.custom_log("HUH", "wtf is that");
    
    std::cout << "Test 1 successfull!" << std::endl;
    return 0;
}

int main(){
    test_simple_logs();
    return 0;
}