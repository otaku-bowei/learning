create table if not exists rbac.`user`
(
    id          bigint       not null comment '用户id'
        primary key,
    user_name   varchar(64)  not null comment '用户名',
    password    varchar(128) not null comment '用户密码',
    age         int          not null comment '用户年龄',
    bithday     datetime     not null comment '生日',
    create_time datetime     not null comment '创建时间',
    update_time datetime     not null comment '更新时间',
    create_user varchar(64)  null comment '创建用户',
    update_user varchar(64)  null comment '更新用户'
)
    comment '用户表';

