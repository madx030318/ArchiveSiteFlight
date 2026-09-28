import hashlib
import hmac

def sha512_hash(data: str) -> str:
  return hashlib.sha512(
    data.encode("utf-8")
  ).hexdigest()

def verify_sha512(data : str, expected_hash : str) -> bool:
  actual_hash = sha512_hash(data)
  return hmac.compare_digest(
        actual_hash,
        expected_hash
    )

if __name__ == "__main__":

    message = "Archive History"

    hashed_message = sha512_hash(message)
    print("Original:")
    print(message)

    print("\nSHA-512:")
    print(hashed_message)

    print("\nVerification:")
    print(verify_sha512(message, hashed_message))
  


