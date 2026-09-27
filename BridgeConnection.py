from flask import Flask, request, jsonify
from bridge import ArchiveBridge

app = Flask(__name__)
bridge = ArchiveBridge()

@app.route("/api/archive", methods = ["GET"])
def get_archive():
  query = request.args.get("query", "")
  year = request.args.get("year")
  category = request.args.get("category")
  source = request.args.get("source")


  results = bridge.search(
    query=query,
    year=year,
    category=category,
    source=source
    )

 return jsonify({
        "status": "success",
        "count": len(results),
        "records": results
    })


@app.route("/api/health", methods=["GET"])
def health():

    return jsonify({
        "status": "online",
        "service": "Archive Python Bridge"
    })


if __name__ == "__main__":

    app.run(
        host="127.0.0.1",
        port=5000,
        debug=True
    )

