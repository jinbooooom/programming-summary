# -*- coding:utf-8 -*-

import sys
import os
from optparse import OptionParser

parser = OptionParser()
parser.add_option('-f', '--file', type = str, default = './readme.md', help='markdown file path')
parser.add_option('-p', '--prefix', type = str, default = '', help='link prefix')

def githubUrl(url):
    # 将空格替换为 "-"
    url = url.replace(" ", "-")

    # 删除掉 specialChars 中的字符，不对 '-' 做任何操作
    englishSpecialChars = r'\/"<>@#$%^&*()+,.!:;`='
    chineseSpecialChars = r'，。、！（）？“”：；|'
    specialChars = englishSpecialChars + chineseSpecialChars
    for specialChar in specialChars:
        url = url.replace(specialChar, '')

    return url

if __name__ == "__main__":
    (options, args) = parser.parse_args()
    (options, args) = parser.parse_args(sys.argv)  
    print("param: ", options)

    filePath, fileName = os.path.split(options.file)
    saveTocName = "toc_" + fileName
    saveTocPath = os.path.join(filePath, saveTocName)
    # https://github.com/jinbooooom/programming-summary/blob/master/C-plus-plus/C-plus-plus.md
    # https://github.com/jinbooooom/programming-summary/blob/master/concurrency-cpp/concurrency.md
    linkPrefix = options.prefix
    
    skip = 0
    with open(options.file, 'r') as fr:
        with open(saveTocPath, 'w') as fw:
            for readLine in fr.readlines():
                # 找到了代码块，就都跳过，不管以 # 开头的内容，因为这在代码区可能指的是注释而不是文本区的标题等级
                if readLine.find("```") == 0:
                    skip = ~skip
                    continue
                    
                if (skip):
                    continue

                if readLine[0] != "#":
                    continue

                level = 0
                while readLine[level] == "#":
                    level += 1

                title_from = level
                title_end = level
                # 去掉末尾的换行和回车
                while readLine[title_end] not in "\r\n":
                    title_end += 1
                title = readLine[title_from : title_end]
                # 去掉左右空格
                title = title.strip()
                # 处理含有超链接的标题 [title](link)
                idx_start = title.find("[")
                idx_end = title.find("](")
                if idx_end != -1:
                    title = title[idx_start + 1 : idx_end]
                # 将空格替换为%20 
                #url = title.replace(' ' , '%20')
                url = title
                url = githubUrl(url)  

                blank_str = ""
                sign_str = "#"
                for i in range(level - 1):
                    blank_str += "  "
                    sign_str += "#"
                # 第一个无序列表不含有空格
                blank_str = blank_str[2: ]
                
                title = f"[{title}]({options.prefix}#{url})"
                title = blank_str + " - " + title + '\n'
                # print(title)
                fw.write(title)

    print(f"save toc file to {saveTocName}")

        