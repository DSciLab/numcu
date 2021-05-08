#include <iostream>
#include <string>
#include <vector>


static std::string SUCCESS = "SUCCESS";
static std::string FAILD = "FAILD";


static void report(std::vector<int> code_list,
                   std::vector<std::string> mod_list);
extern int test_ndarray(void);


int main(void)
{
    std::vector<int> code_list;
    std::vector<std::string> mod_list;
    int code;

    std::cout << "==== TEST START ====" << std::endl;
    std::cout << "Running ndarray ..." << std::endl;
    code = test_ndarray();
    code_list.push_back(code);
    mod_list.push_back("ndarray");

    std::cout << "==== TEST END ====" << std::endl;
    report(code_list, mod_list);
    return code;
}


static void report(std::vector<int> code_list,
                   std::vector<std::string> mod_list)
{
    std::string curr_mod_name;
    std::string status;
    int curr_code;

    std::cout << "==== REPORT START ====" << std::endl;
    for(size_t i = 0; i < code_list.size(); ++i) {
        curr_mod_name = mod_list[i];
        curr_code = code_list[i];
        if(curr_code == 0)
            status = SUCCESS;
        else
            status = FAILD;
        
        std::cout << status << ":" << curr_mod_name << std::endl;
    }
    std::cout << "==== REPORT END ====" << std::endl;
}
