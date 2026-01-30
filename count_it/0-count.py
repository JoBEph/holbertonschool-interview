#!/usr/bin/python3
"""
Recursive function that queries the Reddit API and counts keywords
in hot article titles
"""
import re
import requests


def count_words(subreddit, word_list, after=None, word_count=None):
    """
    Recursively queries Reddit API, parses titles of hot articles,
    and prints a sorted count of given keywords.

    Args:
        subreddit: The subreddit to query
        word_list: List of keywords to count
        after: Reddit pagination parameter (for recursion)
        word_count: Dictionary to accumulate word counts (for recursion)
    """
    if word_count is None:
        word_count = {}
        for word in word_list:
            word_lower = word.lower()
            word_count[word_lower] = 0

    url = f"https://www.reddit.com/r/{subreddit}/hot.json"
    headers = {'User-Agent': 'Mozilla/5.0 (compatible; count_it/1.0)'}
    params = {'limit': 100}

    if after:
        params['after'] = after

    try:
        response = requests.get(url, headers=headers, params=params,
                                allow_redirects=False)

        if response.status_code != 200:
            return

        data = response.json()

        if 'data' not in data or 'children' not in data['data']:
            return

        posts = data['data']['children']

        for post in posts:
            title = post['data']['title'].lower()

            for word in word_count.keys():
                pattern = r'\b' + re.escape(word) + r'\b'
                matches = re.findall(pattern, title)
                word_count[word] += len(matches)

        after = data['data']['after']

        if after:
            count_words(subreddit, word_list, after, word_count)
        else:
            filtered_counts = {k: v for k, v in word_count.items() if v > 0}

            if not filtered_counts:
                return

            sorted_words = sorted(filtered_counts.items(),
                                  key=lambda x: (-x[1], x[0]))

            for word, count in sorted_words:
                print(f"{word}: {count}")

    except Exception:
        return
