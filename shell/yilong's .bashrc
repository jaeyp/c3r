     1 #---------------------------------------------------------------------------------------------------------
     2 #Some personal setup
     3 #----------------------------------------------------------------------------------------------------------
     4 ulimit -S -c 0      #no need any coredump
     5 set -o notify
     6 set -o noclobber
     7 set -o ignoreeof
     8 set -o nounset
     9 #set -o xtrace      #for dubugging
    10 #---------------------------------
    11 
    12 # ~/.bashrc: executed by bash(1) for non-login shells.
    13 # see /usr/share/doc/bash/examples/startup-files (in the package bash-doc)
    14 # for examples
    15 
    16 # If not running interactively, don't do anything
    17 case $- in
    18     *i*) ;;
    19       *) return;;
    20 esac
    21 
    22 # don't put duplicate lines or lines starting with space in the history.
    23 # See bash(1) for more options
    24 HISTCONTROL=ignoreboth
    25 
    26 # append to the history file, don't overwrite it
    27 shopt -s histappend
    28 
    29 # for setting history length see HISTSIZE and HISTFILESIZE in bash(1)
    30 HISTSIZE=1000
    31 HISTFILESIZE=2000
    32 
    33 # check the window size after each command and, if necessary,
    34 # update the values of LINES and COLUMNS.
    35 shopt -s checkwinsize
    36 
    37 # If set, the pattern "**" used in a pathname expansion context will
    38 # match all files and zero or more directories and subdirectories.
    39 #shopt -s globstar
    40 
    41 # make less more friendly for non-text input files, see lesspipe(1)
    42 [ -x /usr/bin/lesspipe ] && eval "$(SHELL=/bin/sh lesspipe)"
    43 
    44 # set variable identifying the chroot you work in (used in the prompt below)
    45 if [ -z "${debian_chroot:-}" ] && [ -r /etc/debian_chroot ]; then
    46     debian_chroot=$(cat /etc/debian_chroot)
    47 fi
    48 
    49 # set a fancy prompt (non-color, unless we know we "want" color)
    50 case "$TERM" in
    51     xterm-color|*-256color) color_prompt=yes;;
    52 esac
    53 
    54 # uncomment for a colored prompt, if the terminal has the capability; turned
    55 # off by default to not distract the user: the focus in a terminal window
    56 # should be on the output of commands, not on the prompt
    57 #force_color_prompt=yes
    58 
    59 if [ -n "$force_color_prompt" ]; then
    60     if [ -x /usr/bin/tput ] && tput setaf 1 >&/dev/null; then
    61     # We have color support; assume it's compliant with Ecma-48
    62     # (ISO/IEC-6429). (Lack of such support is extremely rare, and such
    63     # a case would tend to support setf rather than setaf.)
    64     color_prompt=yes
    65     else
    66     color_prompt=
    67     fi
    68 fi
    69 
    70 #------------------------------------------------------------------------------------------------------
    71 #define some colors
    72 #------------------------------------------------------------------------------------------------------
    73 red='\e[0;31m'
    74 RED='\e[1;31m'
    75 blue='\e[0;34m'
    76 BLUE='\e[1;34m'
    77 cyan='\e[0;36m'
    78 CYAN='\e[1;36m'
    79 NC='\e[0m'      #no color
    80 
    81 echo -e "${CYAN}This is BASH ${RED}${BASH_VERSION%.*}${CYAN} - DISPLAY on ${RED}$DISPLAY${NC}\n"
    82 date
    83 if [ -x /usr/games/fortune ]; then
    84     /usr/games/fortune -s
    85 fi
    86 
    87 #run when exit the shell
    88 function _exit()
    89 {
    90     echo -e "${RED}Hasta la vista, baby${NC}"
    91 }
    92 trap _exit EXIT
    93 
    94 #--------------------------------------------------------------------------------------------------------
    95 #shell prompt
    96 #--------------------------------------------------------------------------------------------------------
    97 if [[ "${DISPLAY#$HOST}" != ":0.0" &&  "${DISPLAY}" != ":0" ]]; then
    98     HILIT=${red}        #remote host
    99 else
   100     HILIT=${cyan}       #local host
   101 fi
   102 
   103 function fastprompt()
   104 {
   105     unset PROMPT_COMMAND
   106     case $TERM in
   107         *term | rxvt )
   108             PS1="${HILIT}[\h]$NC \W > \[\033]0;\${TERM} [\u@\h] \w\007\]" ;;
   109     linux )
   110         PS1="${HILIT}[\h]$NC \W > " ;;
   111         *)
   112             PS1="[\h] \W > " ;;
   113     esac
   114 }
   115 
   116 function powerprompt()
   117 {
   118     _powerprompt()
   119     {
   120         LOAD=$(uptime|sed -e "s/.*: \([^,]*\).*/\1/" -e "s/ //g")
   121     }
   122 
   123     PROMPT_COMMAND=_powerprompt
   124     case $TERM in
   125         *term | rxvt )
   126             PS1="${HILIT}[\A \$LOAD]$NC\n[\h \#] \W > \[\033]0;\${TERM} [\u@\h] \w\007\]" ;;
   127         linux )
   128             PS1="${HILIT}[\A - \$LOAD]$NC\n[\h \#] \w > " ;;
   129         * )
   130             PS1="[\A - \$LOAD]\n[\h \#] \w > " ;;
   131     esac
   132 }
   133 
   134 powerprompt     #default prompt, if slow, use fastprompt
   135 #---------------------------------------------------------------------------------------------------------
   136 
   137 if [ "$color_prompt" = yes ]; then
   138     PS1='${debian_chroot:+($debian_chroot)}\[\033[01;32m\]\u@\h\[\033[00m\]:\[\033[01;34m\]\w\[\033[00m\]\$ '
   139 else
   140     PS1='${debian_chroot:+($debian_chroot)}\u@\h:\w\$ '
   141 fi
   142 unset color_prompt force_color_prompt
   143 
   144 # If this is an xterm set the title to user@host:dir
   145 case "$TERM" in
   146 xterm*|rxvt*)
   147     PS1="\[\e]0;${debian_chroot:+($debian_chroot)}\u@\h: \w\a\]$PS1"
   148     ;;
   149 *)
   150     ;;
   151 esac
   152 
   153 # enable color support of ls and also add handy aliases
   154 if [ -x /usr/bin/dircolors ]; then
   155     test -r ~/.dircolors && eval "$(dircolors -b ~/.dircolors)" || eval "$(dircolors -b)"
   156     alias ls='ls --color=auto'
   157     #alias dir='dir --color=auto'
   158     #alias vdir='vdir --color=auto'
   159 
   160     alias grep='grep --color=auto'
   161     alias fgrep='fgrep --color=auto'
   162     alias egrep='egrep --color=auto'
   163 fi
   164 
   165 # colored GCC warnings and errors
   166 #export GCC_COLORS='error=01;31:warning=01;35:note=01;36:caret=01;32:locus=01:quote=01'
   167 
   168 # some more ls aliases
   169 alias ll='ls -alF'
   170 alias la='ls -A'
   171 alias l='ls -CF'
   172 
   173 #--------------------------------------------------------------------------------------------------------
   174 #personal aliases
   175 #--------------------------------------------------------------------------------------------------------
   176 alias rm='rm -i'
   177 alias cp='cp -i'
   178 alias mv='mv -i'
   179 alias mkdir='mkdir -p'
   180 
   181 alias h='history'
   182 alias j='jobs -l'
   183 alias r='rlogin'
   184 alias which='type -all'
   185 
   186 alias ..='cd ..'
   189 alias la='ls -Al'               #display hiding files
   190 alias ls='ls -hF --color'       #add color to files
   191 alias lx='ls -lXB'              #sort by extension
   192 alias lk='ls -lSr'              #sort by size
   193 alias lc='ls -lcr'              #sort by modification time
   194 alias lu='ls -lur'              #sort by access time
   195 alias lt='ls -ltr'              #sort by date
   196 alias lr='ls -lR'               #recursion ls
   197 alias lm='ls -al |more'
   198 alias tree='tree -Csu'
   199 
   200 #for spelling mistakes
   201 alias xs='cd'
   202 alias vf='cd'
   203 alias moer='more'
   204 alias moew='more'
   205 alias kk='ll'
   206 
   207 #Some functions
   208 function xtitle()
   209 {
   210     case "$TERM" IN
   211         *term | rxvt )
   212             echo -n -e "\033]0;$*\007" ;;
   213         * )
   214         ;;
   215     esac
   216 }
   217 alias top='xtitle Processes on $HOST && top'
   218 alias make='xtitle Making $(basename $PWD) ; make'
   219 alias ncftp="xtitle ncFTP ; ncftp"
   220 
   221 #use name to search file
   222 function ff()
   223 { 
   224     find . -type f -iname '*'$*'*' -ls ;
   225 }
   226 
   227 #cut 10 line of a file
   228 function cuttail()
   229 {
   230     nlines=${2:-10}
   231     sed -n -e :a -e "1,${nlines}!{P;N;D;};N;ba" $1
   232 }
   233 
   234 #exchange the names of two files
   235 function swapname()
   236 {
   237     local TMPFILE=tmp.$$
   238     mv "$1" $TMPFILE
   239     mv "$2" "$1"
   240     mv $TMPFILE "$2"
   241 }
   242 #----------------------------------------------------------------------------------------------------------
   243 
   244 # Add an "alert" alias for long running commands.  Use like so:
   245 #   sleep 10; alert
   246 alias alert='notify-send --urgency=low -i "$([ $? = 0 ] && echo terminal || echo error)" "$(history|tail -n1|s       ed -e '\''s/^\s*[0-9]\+\s*//;s/[;&|]\s*alert$//'\'')"'
   247 
   248 # Alias definitions.
   249 # You may want to put all your additions into a separate file like
   250 # ~/.bash_aliases, instead of adding them here directly.
   251 # See /usr/share/doc/bash-doc/examples in the bash-doc package.
   252 
   253 if [ -f ~/.bash_aliases ]; then
   254     . ~/.bash_aliases
   255 fi
   256 
   257 # enable programmable completion features (you don't need to enable
   258 # this, if it's already enabled in /etc/bash.bashrc and /etc/profile
   259 # sources /etc/bash.bashrc).
   260 if ! shopt -oq posix; then
   261   if [ -f /usr/share/bash-completion/bash_completion ]; then
   262     . /usr/share/bash-completion/bash_completion
   263   elif [ -f /etc/bash_completion ]; then
   264     . /etc/bash_completion
   265   fi
   266 fi
