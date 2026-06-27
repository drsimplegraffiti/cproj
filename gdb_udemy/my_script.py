import gdb

gdb.execute("break main")
gdb.execute("run")

val = gdb.parse_and_eval("a")
print(f"value of a: {val}")
