# 一、对接odb框架
1.linux本地安装odb相关包
2.实现#pragma db object定义文件
3.linux环境使用cmake编译
4.拉取编译好的相关类
5.使用odb包对接相关类的操作，链接需要使用编译后的类，而非定义类
6.生成相应的类
```
ubuntu使用gcc13编译，需要切换gcc版本
odb -x g++-14 -d mysql --std c++11 --profile boost/date-time --generate-query --generate-schema --schema-format sql --output-dir ../src/entity/model User.h

--profile boost/date-time 参数支持日期类型和数据库日期类型转换配置
```

# 二、对接grpc框架
1.在linux安装grpc依赖
```angular2html
# 1. 更新系统包
sudo apt update && sudo apt upgrade -y

# 2. 安装基础编译工具
sudo apt install -y build-essential cmake git pkg-config

# 3. 安装gRPC和Protobuf的依赖库
sudo apt install -y libssl-dev libz-dev

# 4. 克隆gRPC源码（包含子模块，Protobuf是gRPC的子模块）
git clone --recurse-submodules -b v1.62.0 https://github.com/grpc/grpc.git
cd grpc

# 5. 编译并安装gRPC和Protobuf（约10-20分钟，视配置而定）
mkdir -p cmake/build
cd cmake/build

# 配置编译选项（安装到系统目录，方便CLion找到）
cmake -DgRPC_INSTALL=ON \
      -DgRPC_BUILD_TESTS=OFF \
      -DCMAKE_INSTALL_PREFIX=/usr/local \
      ../..

# 编译（-j后接CPU核心数，比如Multipass分配了4核就写-j4）
make -j$(nproc)

# 安装到系统
sudo make install

# 检查protoc（Protobuf编译器）版本
protoc --version  # 应输出 libprotoc 3.x+
# 检查grpc_cpp_plugin（gRPC C++插件）
which grpc_cpp_plugin  # 应输出 /usr/local/bin/grpc_cpp_plugin
```

# 三、对接REST框架
```
需要切换gcc14版本
1.ubuntu安装drogon
2.引入drogon依赖
3.定义接口METHOD
```


# 四、实现一个绿色的rbac系统


# 五、对接ES接口，实现文件检索

# 六、实现ReAct

# 七、实现CoT

# 八、对接日志框架
```
apt install libspdlog-dev
```