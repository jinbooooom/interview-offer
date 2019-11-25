### 检索不同的行 DISTINCT

**DISTINCT：返回某一列不同的值**

```mysql
mysql> SELECT DISTINCT order_num FROM orderitems;
+-----------+
| order_num |
+-----------+
|     20005 |
|     20006 |
|     20007 |
|     20008 |
|     20009 |
+-----------+

#DISTINCT 应用于所有列而不仅仅是前置它的列，
#就是说当某一行 order_num 与 order_item 都一样，那么就过滤掉这一行
mysql> SELECT DISTINCT order_num,order_item FROM orderitems;
+-----------+------------+
| order_num | order_item |
+-----------+------------+
|     20005 |          1 |
|     20005 |          2 |
|     20009 |          4 |
|     20005 |          4 |
|     20009 |          1 |
|     20008 |          1 |
|     20006 |          1 |
|     20009 |          2 |
|     20009 |          3 |
|     20005 |          3 |
|     20007 |          1 |
+-----------+------------+

#下面的语句有问题
mysql> SELECT DISTINCT order_num, DISTINCT order_item FROM orderitems;
```

### 限制结果 LIMIT

```mysql
# 查找 prod_name 的前 5 行，从索引为 0 行开始的后 5 行（行数的序号从 0 开始）
mysql> SELECT prod_name FROM products LIMIT 5;

# 查找 prod_name 从索引为 5 的行开始的后 5 行
mysql> SELECT prod_name FROM products LIMIT 5, 5;
```

### 排序 ORDER BY
```mysql
mysql> SELECT vend_id, vend_name FROM vendors ORDER BY vend_name;

# 按多个列排序，先按州排序，再按城市排序（注意 NULL 会排在前面）
mysql> SELECT vend_id, vend_name, vend_city, vend_state FROM vendors ORDER BY vend_state, vend_city;

# 指定排序方向，按价格降序，按名称升序
mysql> SELECT prod_id, prod_price, prod_name FROM products ORDER BY prod_price DESC,prod_name;

# 价格和名称都升序
mysql> SELECT prod_id, prod_price, prod_name FROM products ORDER BY prod_price DESC,prod_name DESC;

```

### 过滤数据 WHERE
```mysql
# 注意不等于 <>，也可以用 !=，
# 选择在某两个值之间的【范围值检查】 BETWEEN

# 选择价格在闭区间 [5, 10] 的商品
mysql> SELECT prod_name, prod_price FROM products WHERE prod_price BETWEEN 5 AND 10;
+----------------+------------+
| prod_name      | prod_price |
+----------------+------------+
| .5 ton anvil   |       5.99 |
| 1 ton anvil    |       9.99 |
| Bird seed      |      10.00 |
| Oil can        |       8.99 |
| TNT (5 sticks) |      10.00 |
+----------------+------------+

# 空值检查
# 选择没有邮箱的顾客 id、名称
mysql> SELECT cust_id, cust_name FROM customers WHERE cust_email IS NULL;
+---------+-------------+
| cust_id | cust_name   |
+---------+-------------+
|   10002 | Mouse House |
|   10005 | E Fudd      |
+---------+-------------+
```

### 指定条件范围 IN

```mysql
# 查找供应商 1001，1005 的商品名、价格，按升序显示
mysql> SELECT prod_name, prod_price FROM products
    -> WHERE vend_id IN (1001, 1005)
    -> ORDER BY prod_name;
+--------------+------------+
| prod_name    | prod_price |
+--------------+------------+
| .5 ton anvil |       5.99 |
| 1 ton anvil  |       9.99 |
| 2 ton anvil  |      14.99 |
| JetPack 1000 |      35.00 |
| JetPack 2000 |      55.00 |
+--------------+------------+

# NOT 操作符，只有一个功能否定它后面的任何条件
# 查找除供应商 1001，1005 的商品名、价格，按升序显示
mysql> SELECT prod_name, prod_price FROM products
    -> WHERE vend_id NOT IN (1001, 1005)
    -> ORDER BY prod_name;
```

**下面的语句跟上面的一样，但IN有很多优点**

- IN 操作语法清晰直观，计算次序更容易管理
- IN 操作一般比 OR 操作执行更快
- IN 的最大优点是可以包含其他 SELECT 语句

```mysql
mysql> SELECT prod_name, prod_price FROM products
    -> WHERE vend_id = 1001 OR vend_id = 1005
    -> ORDER BY prod_name;
```

### 通配符过滤

```
# 检索商品名字包含 'jet' 的商品
# 百分比 % 表示任何字符串出现任何次数
mysql> SELECT prod_id, prod_name FROM products WHERE prod_name LIKE '%jet%';
+---------+--------------+
| prod_id | prod_name    |
+---------+--------------+
| JP1000  | JetPack 1000 |
| JP2000  | JetPack 2000 |
+---------+--------------+

# 搜索名称以 s 开头 以 e 结尾的商品
mysql> SELECT prod_id, prod_name FROM products WHERE prod_name LIKE 's%e';
+---------+-----------+
| prod_id | prod_name |
+---------+-----------+
| SAFE    | Safe      |
+---------+-----------+

# 下划线 '_' 只能匹配单个字符，而不是多个字符，也不能匹配 0 个。
```

### 正则表达式

### 计算字段

```mysql
# 想让查询的结果显示为 vend_name(vend_country) 格式，使用 AS vend_title 给该字段取别名
mysql> SELECT Concat(vend_name, '(', vend_country, ')') AS vend_title
    -> FROM vendors
    -> ORDER BY vend_name;
+------------------------+
| vend_title             |
+------------------------+
| ACME(USA)              |
| Anvils R Us(USA)       |
| Furball Inc.(USA)      |
| Jet Set(England)       |
| Jouets Et Ours(France) |
| LT Supplies(USA)       |
+------------------------+

# 执行算术运算
mysql> SELECT prod_id, quantity, item_price, quantity * item_price AS expanded_price
    -> FROM orderitems WHERE order_num = 20005;
+---------+----------+------------+----------------+
| prod_id | quantity | item_price | expanded_price |
+---------+----------+------------+----------------+
| ANV01   |       10 |       5.99 |          59.90 |
| ANV02   |        3 |       9.99 |          29.97 |
| TNT2    |        5 |      10.00 |          50.00 |
| FB      |        1 |      10.00 |          10.00 |
+---------+----------+------------+----------------+
```

### 使用数据处理函数

**文本处理**

- Upper()
- Lower()

**日期和时间处理函数**

- Date()     返回日期之间的时间部分
- Year()  Month()  Day()     分别返回日期的年、月、日
- Time()     返回日期的时间部分
- Hour()  Minute()  Second()    分别返回日期的时、分、秒

```mysql
# 返回 2005-09-01 的订单信息
mysql> SELECT cust_id, order_num, order_date FROM orders WHERE Date(order_date) = '2005-09-01';
+---------+-----------+---------------------+
| cust_id | order_num | order_date          |
+---------+-----------+---------------------+
|   10001 |     20005 | 2005-09-01 00:00:00 |
+---------+-----------+---------------------+

# 返回 '2005-09-01' 与 '2005-09-30' 之间（含）的所有订单信息
mysql> SELECT cust_id, order_num, order_date FROM orders
    -> WHERE Date(order_date) BETWEEN '2005-09-01' AND '2005-09-30';
+---------+-----------+---------------------+
| cust_id | order_num | order_date          |
+---------+-----------+---------------------+
|   10001 |     20005 | 2005-09-01 00:00:00 |
|   10003 |     20006 | 2005-09-12 00:00:00 |
|   10004 |     20007 | 2005-09-30 00:00:00 |
+---------+-----------+---------------------+

# 返回 2005 年 9 月份的所有订单记录（这样不用考虑一个月是大月还是小月，是否闰年问题）
mysql> SELECT cust_id, order_num, order_date FROM orders
    -> WHERE Year(order_date) = 2005 AND Month(order_date) = 9;
+---------+-----------+---------------------+
| cust_id | order_num | order_date          |
+---------+-----------+---------------------+
|   10001 |     20005 | 2005-09-01 00:00:00 |
|   10003 |     20006 | 2005-09-12 00:00:00 |
|   10004 |     20007 | 2005-09-30 00:00:00 |
+---------+-----------+---------------------+
3 rows in set (0.00 sec)
```

### 聚集函数

- AVG()    返回某列的均值
- COUNT()    返回某列的行数
- MAX()  Min()    返回某列的最大值、最小值
- SUM()    返回某列值之和   

```mysql
# 计算商品的数量，价格和以及均价（注意 AS 用法）
# 注意 COUNT(*) 对表中行的数目统计。不管行中包含的是空值还是非空值
# COUNT(column) 对特定列中具有值得行进行统计，不包含 NULL 值
mysql> SELECT COUNT(*), SUM(prod_price), AVG(prod_price) AS '均价' FROM products;
+----------+-----------------+-----------+
| COUNT(*) | SUM(prod_price) | 均价      |
+----------+-----------------+-----------+
|       14 |          225.87 | 16.133571 |
+----------+-----------------+-----------+

# 查找供应商 1003 提供的价格不同的商品的均价
mysql> SELECT AVG(DISTINCT prod_price) AS avg_price FROM products WHERE vend_id = 1003;
+-----------+
| avg_price |
+-----------+
| 15.998000 |
+-----------+

# 统计不同供应商的个数
mysql> SELECT COUNT(DISTINCT vend_id) AS num_of_vend FROM products;
+-------------+
| num_of_vend |
+-------------+
|           4 |
+-------------+

# 统计商品数量、最小、最大价格、平均价格
mysql> SELECT COUNT(*) AS num_items,
    -> MIN(prod_price) AS price_min,
    -> MAX(prod_price) AS price_max,
    -> AVG(prod_price) AS price_avg
    -> FROM products;
+-----------+-----------+-----------+-----------+
| num_items | price_min | price_max | price_avg |
+-----------+-----------+-----------+-----------+
|        14 |      2.50 |     55.00 | 16.133571 |
+-----------+-----------+-----------+-----------+
```

### 数据分组 GROUP BY

```mysql
# 返回每一个供应商提供的商品数量
mysql> SELECT vend_id, COUNT(vend_id) AS num_vend_id FROM products GROUP BY vend_id;
+---------+-------------+
| vend_id | num_vend_id |
+---------+-------------+
|    1001 |           3 |
|    1002 |           2 |
|    1003 |           7 |
|    1005 |           2 |
+---------+-------------+
```

### 过滤分组 HAVING

**HAVING 后面似乎常跟着聚集函数**

```mysql
# 查找单价在区间[10, 50]的商品数量大于 2 的供应商的 id，数量
mysql> SELECT vend_id, COUNT(vend_id) AS num_vend FROM products
    -> WHERE prod_price BETWEEN 10 AND 50
    -> GROUP BY vend_id
    -> HAVING COUNT(*) >= 2;
+---------+----------+
| vend_id | num_vend |
+---------+----------+
|    1003 |        4 |
+---------+----------+
```



























