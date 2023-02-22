#include <iostream>
#include <vector>
/**
 * 只有标准命名空间std 才有 cout 和 cin ，所以打印的话需要printf函数来做
*/
namespace alibaba
{
void func()
{
    printf("this is alibaba hello world ");
}
}; // namespace alibaba

namespace baidu
{
void func()
{
    printf("this is baidu hello world ");
}
}; // namespace baidu

using namespace alibaba;
int main()
{
    func();
    printf("\n");
    baidu::func();
    printf("\n");
    return 0;
}