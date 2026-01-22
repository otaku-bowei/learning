#!/bin/bash

# ODB代码生成脚本



echo "========================================"

echo "        ODB代码生成工具"

echo "========================================"



# 配置参数

ODB_COMPILER="/usr/bin/odb"

INCLUDE_DIR="./include"

OUTPUT_DIR="./generated"

DB_TYPE="pgsql"  # 根据你的数据库修改：pgsql/mysql/sqlite/oracle



# 检查ODB编译器

if [ ! -f "$ODB_COMPILER" ]; then

    echo "错误: 找不到ODB编译器，请先安装ODB"

    echo "安装命令: sudo apt-get install odb"

    exit 1

fi



# 创建输出目录

mkdir -p "$OUTPUT_DIR"



# ODB编译选项

ODB_OPTIONS="

    -d $DB_TYPE

    --std c++17

    --generate-query

    --generate-schema

    --schema-name ''

    --schema-format embedded

    --hxx-prologue '#pragma once'

    --output-dir $OUTPUT_DIR

    -I $INCLUDE_DIR

    --show-sloc

    --at-once

"



echo "数据库类型: $DB_TYPE"

echo "头文件目录: $INCLUDE_DIR"

echo "输出目录: $OUTPUT_DIR"

echo ""



# 检查实体类文件

if [ ! -d "$INCLUDE_DIR" ]; then

    echo "错误: 找不到include目录"

    exit 1

fi



ENTITY_FILES=$(find "$INCLUDE_DIR" -name "*.hxx" | wc -l)

if [ "$ENTITY_FILES" -eq 0 ]; then

    echo "错误: 在$INCLUDE_DIR中找不到.hxx实体类文件"

    exit 1

fi



echo "找到 $ENTITY_FILES 个实体类文件:"

find "$INCLUDE_DIR" -name "*.hxx" | while read file; do

    echo "  - $(basename "$file")"

done

echo ""



# 生成ODB代码

echo "开始生成ODB代码..."

echo ""



for header_file in "$INCLUDE_DIR"/*.hxx; do

    if [ -f "$header_file" ]; then

        filename=$(basename "$header_file" .hxx)

        echo "🔧 处理: $filename.hxx"

        

        # 执行ODB编译

        $ODB_COMPILER $ODB_OPTIONS "$header_file"

        

        if [ $? -eq 0 ]; then

            echo "   ✅ 成功生成: $filename"

        else

            echo "   ❌ 失败: $filename"

        fi

        echo ""

    fi

done



echo "========================================"

echo "生成的文件:"

echo "========================================"

ls -la "$OUTPUT_DIR"/* 2>/dev/null || echo "没有生成文件"



# 统计生成结果

echo ""

echo "📊 生成统计:"

echo "  头文件: $(ls "$OUTPUT_DIR"/*.h 2>/dev/null | wc -l)"

echo "  实现文件: $(ls "$OUTPUT_DIR"/*.cpp 2>/dev/null | wc -l)"

echo "  内联文件: $(ls "$OUTPUT_DIR"/*.ipp 2>/dev/null | wc -l)"

echo "  SQL文件: $(ls "$OUTPUT_DIR"/*.sql 2>/dev/null | wc -l)"



echo ""

echo "🎉 ODB代码生成完成！"

echo "下一步: 运行 CMake 构建项目"
