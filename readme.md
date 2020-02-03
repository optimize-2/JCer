## `JCer`

> `JCer`是一个`Console game` `(控制台游戏)`,您可以在该游戏里实施`JFCA`.

## 玩法/用法

运行`main.exe`,通过`w,s,上,下`来选择菜单,`Enter`确认.

### `Classic Mode`

经典模式.

在`Classic Mode`中,您是`x`,您的同学是`o`,您可以通过`a,w,s,d`来操控`x`去`JC`同学.

当您玩得厌烦后,走出教室门便会返回到`Start`菜单.

### `JC`方式:

当您走到`+` `(电脑显示屏)`前时,按一下`w`就可以进入电脑界面

接着依次在键盘上敲击`I`,` `,`A`,`K`,` `,`I`,`O`,`I`,`Enter`.`(注意大小写)`

### `Teacher Mode`

老师模式

同学们不会乱跑了,但是您可以趁他们上厕所时实施`JC`.

您甚至可以在老师去喝咖啡时走到`*` `(不是厕所门)`前按`s` `JC`老师.

当您`JC`老师时,可以用`a`,`w`,`s`,`d`选择同学,按回车控制他们的电脑.

### 陶片 `(Ostrakon)`:

陶片是游戏货币.

当您成功`JC`别人时会获得1陶片.

当您的`JC`速度打破了历史记录会再获得2陶片.

陶片可以用于主菜单的`Shop`.

>`optimize_2`被撤销 **进入主站** 权限,操作原因是: **太菜了**.

### `Shop`

位于主菜单中.

可以在里面使用陶片购买道具.

### `Cappuccino`

价值 : 50陶片.

作用 : 使老师喝咖啡的时间变为原来的3倍.

>哎呀这咖啡怎么这么好喝

### `Save`

位于主菜单中.

玩好游戏之后记得保存!`(不然就什么都没了)`

### `Register`

用于注册用户.

注册流程: `输入用户名 -> 输入密码 -> 重复密码 -> 注册成功 -> 重启游戏 -> Login`

### `Login`

用于登陆.

若您没有账号,可输入`register`,游戏会跳转到注册界面.

### `password.hpp`

内置函数:

```cpp
/*********password.hpp*********/
string encry1(string s,int key);
string decry1(string s,int key);
string encry2(char c);
char decry2(string s);
string encry3(string s,int key);
string decry3(string s,int key);
string encry(string s,int key);
string decry(string s,int key);
```

用于`Login`,`Register`和`Save`.

为了防止一些奇怪的人破译加密方法,我们不提供`password.hpp`.

## 作者

`JCer`的作者是`optimize_2`.

`JCer开发组` : `707285884`.

`JCer`目前属于[IceLava团队](http://icelava.top).
