# `JCer`开发组人员招募

>### 我们需要你的加入!
>
>### 如果您想参与`JCer`开发,或是提前体验最新版,欢迎加入QQ群 : `707285884`.
>
>### 另:`JCer`用户群 : `821057136`

# `JCer`急需内测人员!

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

当您成功`JC`别人时会获得`1`陶片.

当您的`JC`速度打破了历史记录会再获得`2`陶片.

陶片可以用于主菜单的`Shop`.

>`optimize_2`被撤销 **进入主站** 权限,操作原因是: **太菜了**.

### `Shop`

位于主菜单中.

可以在里面使用陶片购买道具.

>### `Cappuccino`
>
>价值 : `50`陶片.
>
>作用 : 使老师喝咖啡的时间变为原来的3倍`(一次性)`.
>
>>哎呀这咖啡怎么这么好喝
>
>### `A bag of Cappuccino`
>
>价值 : `80`陶片`(8折)`.
>
>内含`Cappuccino`*`5`.
>
>### `A box of Cappuccino`
>
>价值 : `150`陶片`(7.5折)`.
>
>内含`Cappuccino`*`10`.
>
>### `Coffee maker`
>
>价值 : `200`陶片.
>
>相当于`Cappuccino`*`Infinity`
>
>`PS`:在购买过该产品后建议不要购买咖啡类产品`(除非您陶片没处用了)`
>
>### Toilet seat
>
>价值:`100`陶片.
>
>可以延长同学们上厕所的时间.`(永久)`
>
>>~~这个道具可以叫餐具.~~
>>
>>---`optimize_2`

### `Bag`

你的仓库.

这里面有各种内容.`(比如成就)`

### `Achievement`

成就.

会显示在仓库里.

`JCer`所有的成就都是隐藏的,并以类似彩蛋的形式出现.

## 极域电子教室系统

一个梗...

您可以通过它控制同学的电脑并`JC`他!

### `Teacher`

喜欢喝咖啡和暴政学生.

当老师在教室的时候,您不能`JC`同学.

### `Save`

本游戏自动保存.

### `Register`

用于注册用户.

注册流程: `输入用户名 -> 输入密码 -> 重复密码 -> 注册成功 -> 重启游戏 -> Login`

### `Login`

用于登陆.

若您没有账号,可输入`register`,游戏会跳转到注册界面.

### `Setting`

设置.

### 简体中文

就是这个啦~

>`Optimize_2不能AK IOI.`

### `English`

就是英语啦...

>`Optimize_2 cannot all kill the International Olympic Informatic.`

### `Chinglish`

中式英语!

~~这个语言纯粹是来搞笑的~~

>`Optimize_2 no can ei kei ai ou ai.`

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