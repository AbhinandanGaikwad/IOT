from flask import Flask, request, jsonify, send_from_directory

app = Flask(__name__)

# In-memory data store
data_store = {}

# Serve the HTML file
@app.route('/')
def serve_html():
    return send_from_directory('static', 'index.html')

# Publish endpoint
@app.route('/publish', methods=['POST'])
def publish():
    content = request.json
    publisher_id = content.get('publisher_id')
    data = content.get('data')

    if not publisher_id or not data:
        return jsonify({'error': 'Invalid input'}), 400
    
    data_store[publisher_id] = data
    return jsonify({'status': 'success'}), 200

# Subscribe endpoint
@app.route('/subscribe/<publisher_id>', methods=['GET'])
def subscribe(publisher_id):
    data = data_store.get(publisher_id)
    if data is None:
        return jsonify({'error': 'No data found for this publisher'}), 404
    
    return jsonify({'data': data}), 200

if __name__ == '__main__':
    app.run(debug=True)
