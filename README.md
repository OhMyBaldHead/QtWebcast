# QtWebcast
这是一个基于Qt的网络直播系统，包含服务端和客户端。  
![DF38C5185F622AC697EE5296FAB307B0](https://github.com/user-attachments/assets/f040e54a-8de1-4562-a729-c64c87a675c3)  
# Qt技术
1,QTcpServer & QSocket & QUdpSocket  
2,Qt多线程  
3,SQLite数据库  
4,各种控件  
5,音视频
# 难点于不足
难点在于客户端服务端处理逻辑  
直播的视频和音频传输目前在局域网中使用的boardcast广播的方式。  
这种方式对于测试代码十分友好但是会存在广播风暴  
可以改进采用组播的方式实时传输音视频

