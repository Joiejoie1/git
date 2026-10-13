#include "builtin.h"
#include "config.h"
#include "environment.h"
#include "gettext.h"
#include "wt-status.h"
#include "commit.h"
#include "pretty.h"
#include "strbuf.h"
#include "parse-options.h"

static const char * const psuh_usage[] = {
	N_("git psuh [<arg>...]"),
	NULL,
};

int cmd_psuh(int argc, const char **argv, const char *prefix, struct repository *repo)
{
	struct wt_status status;
	struct commit *c = NULL;
	struct strbuf commitline = STRBUF_INIT;
	int i;

	struct option options[] = {
		OPT_END()
	};

	argc = parse_options(argc, argv, prefix, options, psuh_usage, 0);

	printf(_("Pony saying hello goes here.\n"));

	printf(Q_("Your args (there is %d):\n",
		  "Your args (there are %d):\n",
		  argc),
	       argc);
	for (i = 0; i < argc; i++)
		printf("%d: %s\n", i, argv[i]);

	printf(_("Your current working directory:\n<top-level>%s%s\n"),
	       prefix ? "/" : "", prefix ? prefix : "");

	repo_config(repo, git_default_config, &status);

	wt_status_prepare(repo, &status);
	printf(_("Your current branch: %s\n"), status.branch);

	c = lookup_commit_reference_by_name("origin/master");
	if (c != NULL) {
		pp_commit_easy(CMIT_FMT_ONELINE, c, &commitline);
		printf(_("Current commit: %s\n"), commitline.buf);
	}

	strbuf_release(&commitline);
	return 0;
}
