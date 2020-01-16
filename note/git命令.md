# 遇到的问题汇总

## git命令

### git分支

查看分支：`git branch`

切换分支：`git checkout`或者`git switch`

创建+切换分支：`git checkout -b`或者`git switch -c`

合并某分支到当前分支：`git merge`

删除分支：`git branch -d`

修改最新提交的commit信息：```git commit --amend```

修改之前的commit信息，可以使用变基（**不要轻易用在和别人共享的分支上**）：```git rebase -i xxxx```

变基：

1. 修改commit message 

2. 把连续的commit合并成1个
3. 把不连续的commit合并成1个

暂存区和HEAD的差异：```git diff --cached```

工作区和暂存区的差异：```git diff```

暂存区恢复成HEAD：```git reset HEAD```，暂存区恢复到了工作区

工作区恢复成暂存区：```git checkout -- <file>```

删除文件并添加到暂存区：```git rm xxx```

重命名文件并添加到暂存区：```git mv xxx```









## vscode断点不生效的问题

使用clang++编译的时候，没有使用 -g 选项生成debug信息，所以断点不生效
