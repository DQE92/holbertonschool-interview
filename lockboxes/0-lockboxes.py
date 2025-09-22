#!/usr/bin/python3
"""
Module for solving the lockboxes problem.
"""


def canUnlockAll(boxes):
    """
    Determines if all boxes can be opened.
    
    Args:
        boxes: A list of lists where each inner list contains keys to other boxes
        
    Returns:
        True if all boxes can be opened, False otherwise
    """
    if not boxes:
        return True
    
    n = len(boxes)
    opened = set([0])
    keys_to_try = list(boxes[0])
    
    while keys_to_try:
        key = keys_to_try.pop(0)
        
        if 0 <= key < n and key not in opened:
            opened.add(key)
            keys_to_try.extend(boxes[key])
    
    return len(opened) == n
