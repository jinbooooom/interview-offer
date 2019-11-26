
## 简单命令
- date  打印日期与时间
- cal  打印日历
```
      十一月 2019        
日 一 二 三 四 五 六  
                1  2  
 3  4  5  6  7  8  9  
10 11 12 13 14 15 16  
17 18 19 20 21 22 23  
24 25 26 27 28 29 30 
```
- df 查看磁盘驱动器的可用空间
- pwd  打印当前目录
- watch -n 5 nvidia-smi  # 查看显卡信息，每隔五秒刷新一次显示
- kill PID：杀死某进程。kill -s 9 PID：强制杀死进程
- du -h或du -h --max-depth=1：linux中查看各文件夹及其子文件夹大小命令，后者以当前目录为节点，只往目录树下查找一层，即当前目录下的文件夹（不包括子文件夹）。
- cd 切换目录
- top 动态显示当前耗费资源最多的进程信息
- ping 测试网速
- clear 清屏
- reboot 重启
## linux常用命令
### ls
- ls | wc -w :查看当前目录下有多少个文件及文件夹（不包括子文件夹）
- ls ~/ 列出来 home 下的文件夹
- ls -la 以长格式(-l)列出所有的(-a)文件夹，也可以写为 ls -l -a
	- ls -laF 用长格式列出所有的文件夹并且在每一个列出的名字后面加上类型指示符（类如是目录名字后面会加一个斜杠），也可写成 ls -l -a -F
- ls -R  连同子目录的内容一起列出（递归列出），等于该目录下的所有文件都会显示出来。也可以直接用 tree 命令(需要先安装 sudo apt install tree)
```
总用量 20
drwxrwxr-x 5 jinbo jinbo 4096 11月 26 09:48 ./
drwxrwxr-x 4 jinbo jinbo 4096 11月 26 09:30 ../
drwxrwxr-x 3 jinbo jinbo 4096 11月 26 09:31 1a/
-rw-rw-r-- 1 jinbo jinbo    0 11月 26 09:48 1a.txt
drwxrwxr-x 2 jinbo jinbo 4096 11月 26 09:30 1b/
drwxrwxr-x 2 jinbo jinbo 4096 11月 26 09:30 1c/
-rw-rw-r-- 1 jinbo jinbo    0 11月 26 09:48 1d

```
### less filename 可以用来查看文件内容，按 Q 可以退出 less 程序
### find：这个命令用于查找文件，功能强大。例如：find ./*.txt，查找当前目录及其子目录下所有扩展名是 .txt 的文件。
	- find *[[:lower:]123] 以小写字母或数字1、2、3中的任一个结尾的任一文件
### file	用于确定文件的种类
```
比如 1.txt 其实是 1.JPEG 重命名的，file 1.txt显示
1.txt: JPEG image data, JFIF standard 1.01, resolution (DPI), density 72x72, segment length 16, baseline, precision 8, 440x440, frames 3
```

### mkdir 创建目录
选项：	-u 只复制那些不存在的文件或更新过的名字(虽文件名改动)
	-i 遇到重复的询问是否覆盖
	-v 移动时显示信息性消息，如 '1c/1a.txt' -> '1c/2b.md'
	-r 操作文件夹及子文件夹

	- mkdir dir1 dir2 path_to/dir3

### cp 复制文件和目录
	- cp path_to1/file1 path_to2/file2 file2若与fil1同名，则覆盖，加上 -i 选项，区别在于覆盖之前通知用户是否覆盖 - cp -i path_to1/file1 path_to2/file2 file2
	- cp file1 file2 dir1 把file1,file2复制到目录dir里，前提dir存在
	- cp -r dir1 dir2 把文件夹dir1递归地复制到dir2（不存在则自动创建）

### mv 移动或者重命名
	- mv item1 item2  与 cp 类似，将文件（或目录）item1 移动（或重命名）为 item2
	- mv item... dir  将一个或多个条目从一个目录移动到另一个目录下


### rm 删除文件
	- rm item...
### ln 创建链接
	- ln file link 用来创建硬链接
	- ln -s item link 用来创建符号链接
硬链接不能引用与该链接不在同一个磁盘分区的文件
硬链接无法引用目录
符号链接指向的文件与符号链接自身几乎没有区别，当删除一个符号链接时，删除的只是符号链接而不是文件本身，如果删除了文件而符号链接依旧存在，这就是坏链接。

### 标准输出重定向
I/O 重定向功能可以指定标准输出内容发送到哪里
```shell
ls -rl > tree_output.txt  # > 表明重新写入，会清除之前写的内容
tree >> tree_output.txt		# >> 表明在之前的内容后追加新内容cat
less tree_output.txt 

```

### tee
从 stdin 读取数据，并输出到 stdout 和文件
```shell
ls -lr | tee ls.txt  
# 跟标准输出重定向区别既可以在终端显示命令结果也输出结果保存到文件
```

### cat
可以在终端显示比较短的文件而不需要分页，功能像 less，但 less 操作与 vi 差不多
cat path/xx.txt
cat 1.md 2.md 把想要的文件内容连接在一起显示
cat 1.md 2.md > my_cat.txt 将连在一起的内容写入到文本，不在终端显示

### head/tail
```shell
head -n 3 xx.txt  # 显示文件前 3 行
tail -n 2 xx.txt  # 显示文件后 2 行	
```

### 管道
管道操作符 | 把一个命令的标准输出传送到另一个命令的标准输入中
```shell
格式 command1 | command2 
ls -lr | less
ls -lr | sort | uniq | less  # ls 的结果用 sort 排序，再取里面不重复的行，最终用 less 显示
cat 1a/2a.txt | wc -l -w  # 1a/2a.txt 的内容是 "hello world!"，该命令打印`      1       2
`表示 1 行 2个单词

```









### 推荐/参考链接

- [Linux Tools Quick Tutorial](https://linuxtools-rst.readthedocs.io/zh_CN/latest/index.html) 

- [Linux常用命令（面试题）](https://blog.csdn.net/qq_40910541/article/details/80686362)
- [深度学习中常用的linux命令](https://blog.csdn.net/ft_sunshine/article/details/91993590)
- [linux 常用的 20 个命令](https://blog.csdn.net/q357010621/article/details/80248611)
- [linux 命令大全](https://www.runoob.com/linux/linux-command-manual.html)

