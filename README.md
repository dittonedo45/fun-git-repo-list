# fun-github-repo-list

A simple, lightweight github user repo (*ls*).
Use it like:
```bash
fgls dittonedo45 | less;

fgls dittonedo45 | while read repo; \
do
		git clone https://github.com/dittonedo45/"$repo"
done
```

## Usage
It is a tool for listing the repos of a __speacified__ **user**.

