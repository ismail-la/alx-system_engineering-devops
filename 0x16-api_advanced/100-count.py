#!/usr/bin/python3
""" raddit api
Script to count subreddit titles with keywords
"""
import requests


def count_words(subreddit, word_list, instance={}, after="", count=0):
    """Get count of subreddit titles with keywords.
    """
    # Get data
    response = requests.request(
        'GET',
        'https://www.reddit.com/r/{}/hot.json?limit=100&after={}&count={}'.
        format(subreddit, after, count),
        headers={
            'User-Agent': 'my browser'
        },
        allow_redirects=False
    )
    try:
        result = response.json()
        if response.status_code == 404:
            raise Exception
    except Exception:
        print("")
        return

    result = result.get("data")
    after = result.get("after")
    count += result.get("dist")
    for i in result.get("children"):
        title = i.get("data").get("title").lower().split()
        for word in word_list:
            if word.lower() in title:
                time = len([t for t in title if t == word.lower()])
                if instance.get(word) is None:
                    instance[word] = time
                else:
                    instance[word] += time

    if after is None:
        if len(instance) == 0:
            print("")
            return
        instances = sorted(instance.items(), key=lambda kv: (-kv[1], kv[0]))
        [print("{}: {}".format(k, v)) for k, v in instance]
    else:
        count_words(subreddit, word_list, instance, after, count)
