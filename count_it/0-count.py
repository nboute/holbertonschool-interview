#!/usr/bin/python3

"""0-count.py
Count it! module"""

import requests


def count_words(subreddit, word_list, titles_count={}, after=None):
    """Count words function
    Args:
        subreddit: subreddit to search
        word_list: list of words to search
    """
    if subreddit is None or subreddit == "":
        return None
    if word_list is None or word_list == []:
        return None

    url = "https://www.reddit.com/r/{}/hot.json".format(subreddit)
    headers = {'user-agent': 'my-app/0.0.1'}
    params = {'after': after} if after else {}
    res = requests.get(url, headers=headers, params=params,
                       allow_redirects=False)
    if res.status_code != 200:
        return None

    word_list = list(map(lambda x: x.lower(), word_list))
    word_list.sort()

    res_json = res.json()
    res_data = res_json.get("data")
    res_children = res_data.get("children")
    prev_after = after
    after = res_data.get("after")

    if (titles_count.keys().__len__() == 0):
        for word in word_list:
            titles_count[word] = 0

    for child in res_children:
        child_data = child.get('data')
        title = child_data.get('title')
        title_words = title.lower().split()
        for word in word_list:
            titles_count[word] += title_words.count(word.lower())
    if after is not None:
        count_words(subreddit, word_list, titles_count, after)

    if prev_after is None:
        for key, value in titles_count.items():
            if titles_count[key] != 0:
                print("{}: {}".format(key, value))

    return titles_count
