# PicoIdeal

## 🍊项目简介

基于Netty和json格式的自定义协议物联网云平台（目前实现了基本的数据传输流程和设备接入的管理，平台代码全部开源，可以二次开发，并提供一个温湿度计的硬件接入示例，全套的解决方案，欢迎Star⭐️）

项目演示视频：[bilibili](https://www.bilibili.com/video/BV1mr4y1x7e1)

## 🍒目录结构

- cloud 平台后端，采用Spring Boot、JWT、MyBatis、Netty
- cloud-ui 平台前端，采用Vue、Element-ui、Axios、Echarts
- framework 旋转太空人主题温湿度计硬件代码，采用乐鑫官方ESP-IDF框架（IDF版本v4.3.2）
- hardware 旋转太空人主题温湿度计原理图和PCB，已经开源到了[立创开源硬件平台](https://oshwhub.com/xywang/picoideal)

## 🍓如何使用

### 🍚后端部分
导入 cloud 目录到idea，配置好jdk和maven，修改redis和mysql配置；将picoideal.sql导入到mysql数据库。

### 🍜 前端部分
安装node.js，进入到 cloud-ui 目录，然后运行
```
npm run serve
```
### 🍨硬件代码

安装乐鑫 ESP-IDF 并配置好环境（我是用 vscode 和 Espressif IDF 插件开发的）

### 🍧硬件原理图和PCB

将 hardware 中的文件导入到立创 eda （也可以直接访问 [立创开源硬件平台](https://oshwhub.com/xywang/picoideal)），在立创 eda 中可导出 Gerber 和 BOM

### 🍹接入认证

客户端与云平台建立连接后，发送的第一条数据为认证数据，格式如下

```
{"deviceSn":10112345678,"devicePwd":"abcdefghijkl"}
```
deviceSn 和 devicePwd 需要在先在云平台创建，如果 deviceSn 不存在或 devicePwd 不正确，则云平台主动关闭连接，正确则客户端按照自定义的json格式协议向云平台发送数据

## 🍍系统结构图

![](https://raw.githubusercontent.com/hsinyuwang/PicoIdeal/main/assets/9.png)

## 🍇平台截图

<table>
    <tr>
        <td><img src="https://raw.githubusercontent.com/hsinyuwang/PicoIdeal/main/assets/1.png"/></td>
        <td><img src="https://raw.githubusercontent.com/hsinyuwang/PicoIdeal/main/assets/2.png"/></td>
    </tr>
    <tr>
        <td><img src="https://raw.githubusercontent.com/hsinyuwang/PicoIdeal/main/assets/3.png"/></td>
        <td><img src="https://raw.githubusercontent.com/hsinyuwang/PicoIdeal/main/assets/4.png"/></td>
    </tr>
    <tr>
        <td><img src="https://raw.githubusercontent.com/hsinyuwang/PicoIdeal/main/assets/5.png"/></td>
        <td><img src="https://raw.githubusercontent.com/hsinyuwang/PicoIdeal/main/assets/6.png"/></td>
    </tr>
</table>

## 🍅硬件成品图

<table>
    <tr>
        <td><img src="https://raw.githubusercontent.com/hsinyuwang/PicoIdeal/main/assets/7.jpg"/></td>
        <td><img src="https://raw.githubusercontent.com/hsinyuwang/PicoIdeal/main/assets/8.jpg"/></td>
    </tr>
</table>