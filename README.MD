# 2017.8.27 @ user.cpp, user.h
****
## User 类完成，提供如下接口：
* Login( ) 函数
  * 使用当前 **User** 实例中的用户名和密码登录用户
  * 登录成功后会自动从当前目录下 **userdata/** 文件夹中的以该用户名命名的文件中读取用户数据，恢复 **User.Player** 中所有属性的值
  * 如果登录失败（例如密码错误）则返回 **False**，登录成功返回 **True**
* Register( ) 函数
  *  使用当前 **User** 实例中的用户名和密码注册一个新用户
  *  注册成功后会在当前目录下 **userdata/** 文件夹中创建以该用户名命名的文件
  *  如果注册失败（例如用户名已存在）则返回 **False**，注册成功返回 **True**
* Is_Login( ) 函数
  * 记录用户是否是登录成功的状态，如果是登录成功的状态返回 **True**，否则返回 **False**
* Save ( ) 函数
  * 保存用户的当前状态（ **User.Player** 中的所有属性的值）
  * 保存成功返回 **True**，否则（在用户未登录的情况下保存）返回 **False**
* DeleteUser ( ) 函数
  * 删除当前用户
  * 必须在用户登录的情况下，如果在用户未登录时使用该函数，则返回 **False**
  * 删除成功返回 **True**，否则（该用户未注册）返回 **False**
* **User** 类中Player属性公有

### User 类中存在一个函数对写入和读取存档时的数据进行加密解密，以防止用户恶意修改存档，但该接口不对外开放
### 构造函数为 User ( string username , string password );
### 该类的属性只有 Player 成员外界可访问
### 另外，请在 Player 类中对该类声明友元
****
# 2017.8.28 @ user.cpp, user.h
****
新增 **Get_Username( )** 和 **Get_Password( )** 两个接口，返回用户名和密码（string类）
****
# 2017.8.30 @ user.cpp, user.h
****
更改加密算法，新增：
* 每个 **User** 登录后有三个 **player** 可选择
* 新增 **Select_Player ( int no )** 函数，**no** 可选值为**1,2或3**，选择成功返回**no**的值，选择失败（用户未登录或选择的 **no** 不存在）返回**0**
* **User**中的**Player属性**为指向**Player类**的指针，指向**Select_Player**所选择的**player**
****
# 2017.8.30 @ main.cpp, mudgame.cpp, mudgame.h, commder.cpp, commder.h
* 新增 **Mudgame** 类
* 将 **main** 函数中的逻辑代码移动到 **Mudgame** 类中
  * 该类提供三个接口，这三个接口均需要 **User类的指针** 作为参数
  * 第一个接口 **Init(User*& user)** 包含了用户的初始化界面，登录，注册功能
  * 第二个接口 **Select_Archive ( User* user )** 包含了用户选择存档的功能
  * 第三个接口 **Run ( User* user )** 中包含了游戏的主逻辑循环
* 新增 **Commder** 类用于存储并执行用户输入的命令，将命令与Player类分开