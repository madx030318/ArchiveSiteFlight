import re

def validate_search_query(query: str) -> bool:
  
    if not isinstance(query, str):
        return False

    if len(query) > 100:
        return False

    pattern = r"^[a-zA-Z0-9\s\-_.]*$"

    return re.fullmatch(pattern, query) is not None
