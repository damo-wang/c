# laby
laby是一款编程游戏

## laby 的安装
### ubuntu下apt-get安装
sudo apt-get install laby
> 提前需要apt-get update

## 支持命令
```c
///usr/share/laby/mods/c/lib
enum tile {
  laby_name_Void,
  laby_name_Wall,
  laby_name_Rock,
  laby_name_Web,
  laby_name_Exit,
  laby_name_Unknown
};

extern void laby_name_left();
extern void laby_name_right();
extern void laby_name_forward();
extern void laby_name_escape();
extern void laby_name_take();
extern void laby_name_drop();
extern enum tile laby_name_look();
extern void laby_name_say(char *s);
```

## 修改地图

    /usr/share/laby/levels

