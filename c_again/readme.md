In NERDTree, all file operations live in one menu. Put the cursor on a file or folder in the tree and press **`m`**. A menu appears at the bottom:

```
NERDTree Menu. Use j/k/enter and the shortcuts indicated
==========================================================
> (a)dd a childnode
  (m)ove the current node
  (d)elete the current node
  (c)opy the current node
```

Then press the letter shown:

| Keys | Action |
|---|---|
| `m` then `a` | add a new file or folder |
| `m` then `m` | rename / move the selected node |
| `m` then `d` | delete the selected node |
| `m` then `c` | copy the selected node |

**Adding a file or folder**

1. Put the cursor on a **folder** (or on a file in the folder where you want the new item).
2. Press `m`, then `a`.
3. Type the name and press Enter.
   - `newfile.c` creates a file.
   - `newfolder/` (with a trailing slash) creates a folder.
   - `src/utils/helper.c` creates the folders as needed, then the file.

**Editing a file**

Editing is just opening it:

| Key | Action |
|---|---|
| `Enter` or `o` | open in the current window |
| `i` | open in a horizontal split |
| `s` | open in a vertical split |
| `t` | open in a new tab |

To rename, use `m` then `m` and type the new name.

**Deleting**

Press `m`, then `d`, then confirm with `y`. NERDTree deletes the file permanently, with no trash, so be careful.

**Other useful keys in the tree**

| Key | Action |
|---|---|
| `R` | refresh the tree (use this if a file was changed outside Vim) |
| `I` | show or hide dotfiles |
| `C` | make the selected folder the root |
| `u` | go up one directory |
| `?` | show all NERDTree keys |

**Optional: skip the menu with direct mappings.** If you want to press fewer keys, add this to the NERDTree section of your vimrc:

```vim
let g:NERDTreeMapMenu = 'm'
```

That is already the default, so no change is needed. If you would rather use a menu-free command, you can also use `:!touch filename` or `:e path/to/newfile` from inside Vim, then save with `:w`. The new file shows up in the tree after pressing `R`.


volatile 	Tells the compiler that a variable can change at any time, for example by hardware, so it must always read the value from memory
