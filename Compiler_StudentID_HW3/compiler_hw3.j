.class public compiler_hw3
.super java/lang/Object
.field public static a I = 1
.field public static b I
.field public static c F = 3.14
.field public static d F
.field public static e Ljava/lang/String; = "E"
.field public static f Z = 1
.field public static g Z
.method public static func1()V
.limit stack 50
.limit locals 50
	ldc 0
	istore 0
	ldc 1
	istore 1
	ldc 2.0
	f2i
	istore 2
	ldc 0.0
	fstore 3
	ldc 1.0
	fstore 4
	ldc 2
	i2f
	fstore 5
	ldc 1
	istore 6
	ldc 0
	istore 7
	ldc "I"
	astore 8
.end method
.method public static func2()V
.limit stack 50
.limit locals 50
	ldc 1
	ldc 2.0
1(int) + 2.0(float)
	swap
	i2f
	fadd
	f2i
	istore 0
	ldc 1.0
	ldc 2
1.0(float) * 2(int)
	i2f
	fmul
	fstore 1
	ldc 3
	ldc 5
	irem
	istore 2
	ldc 3
	ldc 5
	irem
	i2f
	fstore 3

	ldc 1
	ldc 2
1(int) + 2(int)
	iadd
( 3(int) )
	ldc 3
	ldc 4
3(int) * 4(int)
	imul
( 12(int) )
	ldc 5
2(int) / 5(int)
	idiv
5(b) - 0(int)
	fsub

	ldc 1
	ldc 2
1(int) + 2(int)
	iadd
( 3(int) )
	ldc 3
5(i) - 3(int)
	fsub
( 5(float) )
	ldc 4
5(float) * 4(int)
	i2f
	fmul
	ldc 5
5(float) / 5(int)
	i2f
	fdiv
.end method
