#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <libavformat/avio.h>
#include <jansson.h>

static int mi_cb(void *b, int l, void *d)
{
    int ret = 0;
    do {
	ret = avio_read((AVIOContext *) d, b, l);
    } while (ret < 0 && ret != AVERROR_EOF);

    return ret == AVERROR_EOF ? 0 : ret;
}

int main(argsc, args, env)
int argsc;
char **args, **env;
{
    int ret = 0;
    AVIOContext *io = 0;
    char *url = "https://api.github.com/users/dittonedo45/repos";

    ret = avio_open(&io, url, AVIO_FLAG_READ);

    if (ret < 0)
	return 1;

    do {
	json_t *a = json_load_callback(mi_cb, io, 0, 0);
	if (!a)
	    break;
// To Be finished
    } while (0);

    avio_close(io);
    return 0;
}
