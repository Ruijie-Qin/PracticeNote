# 遇到的问题汇总

## git命令

### git分支

查看分支：`git branch`

创建分支：`git branch`

切换分支：`git checkout`或者`git switch`

创建+切换分支：`git checkout -b`或者`git switch -c`

合并某分支到当前分支：`git merge`

删除分支：`git branch -d`

## vscode断点不生效的问题

使用clang++编译的时候，没有使用 -g 选项生成debug信息，所以断点不生效
