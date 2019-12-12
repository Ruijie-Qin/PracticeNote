# PracticeNote
用来练习的代码和笔记

代码都位于src目录下面

# 编译方法
通过Makefile文件进行编译。
编译运行的方式：
1. 直接F5直接调试，
2. shift+command+p：输入 Tasks: Run Task 进行编译；输出结果为 ./output/main.out，可以通过命令行执行

# c_cpp_properties.json
删掉了下面的内容，否则microsoft.vscode.cpp.extension.darwin占用CPU太高了
"macFrameworkPath": [
    "/System/Library/Frameworks",
    "/Library/Frameworks"
],
