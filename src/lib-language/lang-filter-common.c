/* Copyright (c) 2016-2018 Dovecot authors, see the included COPYING file */

#include "lib.h"
#include "str.h"
#include "buffer.h"
#include "unichar.h"
#include "lang-filter-private.h"
#include "lang-filter-common.h"
#include "lang-tokenizer-common.h"

void lang_filter_truncate_token(string_t *token, size_t max_length)
{
	if (str_len(token) <= max_length)
		return;

	size_t len = max_length;
	lang_tokenizer_delete_trailing_partial_char(token->data, &len);
	str_truncate(token, len);
	i_assert(len <= max_length);
}
